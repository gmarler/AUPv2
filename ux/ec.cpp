#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <csignal>

#include "ec.hpp"

#define EC_EINTERNAL INT_MAX

static struct {
  char *ms_cat;
  intptr_t ms_code;
  char *ms_macro;
  char *ms_desc;
} macrostr_db[] = {
#include "macrostr.incl"
  { NULL, 0, NULL, NULL}
};

char *get_macrostr(const char *cat, int code, char **desc)
{
  int i;

  for (i = 0; macrostr_db[i].ms_cat != NULL; i++)
    if (std::strcmp(macrostr_db[i].ms_cat, cat) == 0 &&
        macrostr_db[i].ms_code == code) {
      if (desc != NULL)
        *desc = macrostr_db[i].ms_desc;
      return macrostr_db[i].ms_macro;
    }
  if (desc != NULL)
    *desc = "?";
  return "?";
}

/*[syserrmsg-1]*/
char *syserrmsgtype(char *buf, size_t buf_max, const char *msg,
                    int errno_arg, EC_ERRTYPE type)
{
  const char *errmsg;
  char *cat = "?";

  if (msg == NULL)
    msg = "???";
  if (errno_arg == 0)
    // std::snprintf isn't defined until C++11 - so cheat with sprintf
    // snprintf(buf, buf_max, "%s", msg);
    std::sprintf(buf, "%s", msg);
  else {
    if (errno_arg == EC_EINTERNAL)
      errmsg = "Internal error (nonstandard)";
    else if (type == EC_EAI) {
      cat = "eai";
      // errmsg = gai_strerror(errno_arg);
      errmsg = "Need to implement gai_strerror()";
    }
    else if (type == EC_GETDATE)
      // errmsg = getdate_strerror(errno_arg);
      errmsg = "Need to implement getdate_strerror()";
    else {
      cat = "errno";
      errmsg = std::strerror(errno_arg);
    }
    /*errmsg = strerror(errno_arg);*/
    // std::snprintf isn't defined until C++11 - so cheat with sprintf
    // sprintf(buf, buf_max, "%s\n\t\t*** %s (%d: \"%s\") ***", msg,
    //    get_macrostr(cat, errno_arg, NULL), errno_arg,
    //    errmsg != NULL ? errmsg : "no message string");
    sprintf(buf, "%s\n\t\t*** %s (%d: \"%s\") ***", msg,
            get_macrostr(cat, errno_arg, NULL), errno_arg,
            errmsg != NULL ? errmsg : "no message string");
  }
  return buf;
}


/*[ec_atexit_fcn]*/
static void ec_atexit_fcn(void)
{
  ec_print();
}

/*[ec_node]*/
static struct ec_node {
  struct ec_node *ec_next;
  int ec_errno;
  EC_ERRTYPE ec_type;
  char *ec_context;
} *ec_head, ec_node_emergency;

static char ec_s_emergency[100];

static void ec_mutex(bool lock)
{
  static pthread_mutex_t ec_mtx = PTHREAD_MUTEX_INITIALIZER;
  int errnum;
  char *msg;

  if (lock) {
    if ((errnum = pthread_mutex_lock(&ec_mtx)) == 0)
      return;
  }
  else {
    if ((errnum = pthread_mutex_unlock(&ec_mtx)) == 0)
      return;
  }
  if ((msg = std::strerror(errnum)) == NULL)
    std::fprintf(stderr, "Mutex error in ec_* function: %d\n", errnum);
  else
    std::fprintf(stderr, "Mutex error in ec_* function: %s\n", msg);
  std::exit(EXIT_FAILURE);
}

void ec_push(const char *fcn, const char *file, int line,
             const char *str, int errno_arg, EC_ERRTYPE type)
{
  struct ec_node node, *p;
  size_t len;
  static bool attexit_called = false;
  const char *SEP1 = " [";
  const char *SEP2 = ":";
  const char *SEP3 = "] ";

  ec_mutex(true);
  node.ec_errno = errno_arg;
  node.ec_type = type;
  if (str == NULL)
    str = "";
  len = std::strlen(fcn) + std::strlen(SEP1) + std::strlen(file) +
        std::strlen(SEP2) + 6 + std::strlen(SEP3) + std::strlen(str) + 1;
  node.ec_context = (char *)std::calloc(1, len);
  if (node.ec_context == NULL) {
    if (ec_s_emergency[0] == '\0')
      node.ec_context = ec_s_emergency;
    else
      node.ec_context = "?";
    len = sizeof(ec_s_emergency);
  }
  if (node.ec_context != NULL)
    // std::snprintf isn't defined until C++11 - so cheat with sprintf
    // std::snprintf(node.ec_context, len, "%s%s%s%s%d%s%s", fcn, SEP1,
    //              file, SEP2, line, SEP3, str);
    std::sprintf(node.ec_context, "%s%s%s%s%d%s%s", fcn, SEP1,
                  file, SEP2, line, SEP3, str);
  p = (struct ec_node *)std::calloc(1, sizeof(struct ec_node));
  if (p == NULL && ec_node_emergency.ec_context == NULL)
    p = &ec_node_emergency; /* use just once */
  if (p != NULL) {
    node.ec_next = ec_head;
    ec_head = p;
    *ec_head = node;
  }
  if (!attexit_called) {
    attexit_called = true;
    ec_mutex(false);
    if (std::atexit(ec_atexit_fcn) != 0) {
      ec_push(fcn, file, line, "atexit failed", errno, EC_ERRNO);
      ec_print(); /* so at least the error gets shown */
    }
  }
  else
    ec_mutex(false);
}

/*[ec_print]*/
void ec_print(void)
{
  struct ec_node *e;
  int level = 0;

  ec_mutex(true);
  for (e = ec_head; e != NULL; e = e->ec_next, level++) {
    char buf[200], buf2[25 + sizeof(buf)];

    if (e == &ec_node_emergency)
      std::fprintf(stderr, "\t*** Trace may be incomplete ***\n");
    syserrmsgtype(buf, sizeof(buf), e->ec_context,
                  e->ec_next == NULL ? e->ec_errno : 0, e->ec_type);
    // std::snprintf isn't defined until C++11 - so cheat with sprintf
    // std::snprintf(buf2, sizeof(buf2), "%s\t%d: %s",
    //              (level == 0 ? "ERROR:" : ""), level, buf);
    std::sprintf(buf2, "%s\t%d: %s",
                  (level == 0 ? "ERROR:" : ""), level, buf);
    std::fprintf(stderr, "%s\n", buf2);
    // TODO: Determine if the below is really important or not
    // logfmt(buf2);
  }
  ec_mutex(false);
}


