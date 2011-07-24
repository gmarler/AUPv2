/*
	Copyright 2003 by Marc J. Rochkind. All rights reserved.
	May be copied only for purposes and under conditions described
	on the Web page www.basepath.com/aup/copyright.htm.

	The Example Files are provided "as is," without any warranty;
	without even the implied warranty of merchantability or fitness
	for a particular purpose. The author and his publisher are not
	responsible for any damages, direct or incidental, resulting
	from the use or non-use of these Example Files.

	The Example Files may contain defects, and some contain deliberate
	coding mistakes that were included for educational reasons.
	You are responsible for determining if and how the Example Files
	are to be used.

*/
#ifndef _UX_HPP_
#define _UX_HPP_

/*   #include "../include/defs.h"  */
/*  BEGINNING of definition for defs.h replacement */

#if defined(SOLARIS) || defined(HPUX)
#ifndef __EXTENSIONS__
#define __EXTENSIONS__ /* sys/stat.h won't compile without this */
#endif
#endif
#include <sys/stat.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#if defined(SOLARIS) || defined(HPUX)
#ifdef UNDEF__EXTENSIONS__
#undef __EXTENSIONS__
#endif
#endif

/*[defs2]*/
#include <time.h>
#include <limits.h>
#if defined(SOLARIS)
#define _VA_LIST /* can't define it in stdio.h */
#endif
#include <stdio.h>
#if defined(SOLARIS)
#undef _VA_LIST
#endif
#include <stdarg.h> /* this is the place to define _VA_LIST */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#ifndef AUP2_SKIP_WAIT
#include <sys/wait.h>
#endif

/*   #if _XOPEN_SOURCE >= 4 */
#include <sys/statvfs.h>                                                                                                   
#define STATVFS_NAME statvfs
#define FSTATVFS_NAME fstatvfs
/*  #else "Need statvfs/fstatvfs or nonstandard substitute
    #endif */

const char *getdate_strerror(int e);

const char *getdate_strerror(int e)
{
	const char *s[] = {
		"Invalid getdate_err value",
		"DATEMSK environment variable null or undefined",
		"Template file cannot be opened for reading",
		"Failed to get file status information",
		"Template file not a regular file",
		"I/O error encountered while reading template file",
		"Memory allocation failed",
		"No line in template that matches input",
		"Invalid input specification"
	};
	if (e < 1 || e > 8)
		return s[0];
	return s[e];
}

/*  END of definition for defs.h replacement */


typedef enum {EC_ERRNO = 0, EC_EAI = 1, EC_GETDATE = 2, EC_NONE = 3} EC_ERRTYPE;
/*
	File-permission-bit symbols
*/
/*[defs-perm]*/
#define PERM_DIRECTORY	S_IRWXU
#define PERM_FILE		(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
/*[]*/
#include <iostream.h>

/**
	\ingroup Ux
*/
namespace Ux {

/**
	\ingroup Ux
*/
class Base {

};

} // namespace

/* Following for statvfs functions */
#include <sys/statvfs.h>

#include "uxaio.hpp"
#include "uxdir.hpp"
#include "uxdirstream.hpp"
#include "uxerr.hpp"
#include "uxexitstatus.hpp"
#include "uxfile.hpp"
#include "uxnetdb.hpp"
#include "uxposixipc.hpp"
#include "uxprocess.hpp"
#include "uxsigset.hpp"
#include "uxsocket.hpp"
#include "uxsystem.hpp"
#include "uxsysvipc.hpp"
#include "uxterminal.hpp"
#include "uxtime.hpp"
#include "uxtimetm.hpp"

#endif // _UX_HPP_
