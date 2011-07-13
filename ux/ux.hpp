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
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
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
