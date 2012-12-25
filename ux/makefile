# Do not edit this makefile. It was generated automatically 
# with commands like
#
#     $ AUPSRC=/aup # (for example)
#     $ export AUPSRC
#     $ awk -f $AUPSRC/makebuild.awk $AUPSRC/c1/makebuild.spec >$AUPSRC/c1/Makefile
#
# It is incomplete in the sense that there are no header-file
# dependencies.
#
# Use the shell-procedure makebuild to run awk. Then compile
# with a shell-procedure like this one for Linux:
#
# 	AUPSRC=/aup # (for example)
# 	OS=LINUX
# 	LIBS="-lncurses -lutil"
# 	TLIBS=-pthread
# 	export OS LIBS TLIBS
# 	make $2 -f $AUPSRC/$1/Makefile $3
#

defaulttarget: all
# Following must be defined in the environment before you run make:
#
#	OS = SOLARIS or LINUX or FREEBSD
#	LIBS = regular (non-thread) libraries (eg, "-lncurses -lutil")
#	TLIBS = thread libraries (eg, "-llthread -llgcc_r")
#	PTHREADSTUB = stub for thread functions (eg, pthreadstub.o), if needed
#	INCLUDES = additional include directory (eg, "-I/usr/local/include/pthread/linuxthreads")
#	Don't forget:
#		export OS LIBS TLIBS PTHREADSTUB INCLUDES
#	Suggestions:
#		Solaris:
#			OS=SOLARIS
#			LIBS="-lrt -lcurses -lsocket -lnsl"
#			TLIBS="-lpthread"
#
#		FreeBSD:
#			OS=FREEBSD
#			LIBS="-lncurses -lutil"
#			TLIBS="-llthread -llgcc_r"
#			PTHREADSTUB=pthreadstub.o
#			INCLUDES="-I/usr/local/include/pthread/linuxthreads"
#
#		Linux:
#			OS=LINUX
#			LIBS="-lncurses -lutil"
#			TLIBS="-pthread"
#
#	NOTE: -KPIC is for 32-bit, -Kpic is for 64-bit?
OS = SOLARIS
CFLAGS =   -I. -I../include -I../common -I../c6 -D$(OS) -D_REENTRANT -D_THREAD_SAFE \
		-D_POSIX_PTHREAD_SEMANTICS -D_XOPEN_SOURCE=500 -D__EXTENSIONS__ -KPIC
CXXFLAGS = -I. -I../include -I../common -I../c6 -D$(OS) -D_REENTRANT -D_THREAD_SAFE \
					 -D_XOPEN_SOURCE=500 -D__EXTENSIONS__ -D_POSIX_PTHREAD_SEMANTICS -KPIC
CC = /opt/solarisstudio12.3/bin/cc
CXX = /opt/solarisstudio12.3/bin/CC

UXHDRS = \
	ux.hpp \
	uxaio.hpp \
	uxdir.hpp \
	uxdirstream.hpp \
	uxerr.hpp \
	uxexitstatus.hpp \
	uxfile.hpp \
	uxnetdb.hpp \
	uxposixipc.hpp \
	uxprocess.hpp \
	uxsigset.hpp \
	uxsocket.hpp \
	uxsystem.hpp \
	uxsysvipc.hpp \
	uxterminal.hpp \
	uxtime.hpp \
	uxtimetm.hpp

OBJS = \
	uxsystem.o\
	uxsocket.o \
	uxnetdb.o \
	uxtime.o \
	uxterminal.o\
	uxprocess.o\
	uxposixipc.o\
	uxtestfile.o\
	uxsysvipc.o\
	ux.o\
	uxaio.o\
	uxdir.o\
	uxdirstream.o\
	uxerr.o\
	uxexitstatus.o\
	uxfile.o\
	uxtimetm.o \
	$(AUPOBJS) $(PTHREADSTUB) getdate_strerror.o

lib_OBJS := $(filter-out uxtestfile.o, $(OBJS))
libUX.so: $(lib_OBJS)
	$(CXX) -G -i -o libUX.so $(lib_OBJS)

tf: $(OBJS)
	$(CXX) -o tf $(OBJS) $(LIBS)

uxtestfile.o: uxtestfile.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxtestfile.o uxtestfile.cpp

uxfile.o: uxfile.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxfile.o uxfile.cpp

uxerr.o: uxerr.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxerr.o uxerr.cpp

uxdir.o: uxdir.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxdir.o uxdir.cpp

uxdirstream.o: uxdirstream.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxdirstream.o uxdirstream.cpp

uxprocess.o: uxprocess.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxprocess.o uxprocess.cpp

uxaio.o: uxaio.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxaio.o uxaio.cpp

uxsystem.o: uxsystem.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxsystem.o uxsystem.cpp

ux.o: ux.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o ux.o ux.cpp

uxexitstatus.o: uxexitstatus.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxexitstatus.o uxexitstatus.cpp

uxtimetm.o: uxtimetm.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxtimetm.o uxtimetm.cpp

uxtime.o: uxtime.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxtime.o uxtime.cpp

uxsocket.o: uxsocket.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxsocket.o uxsocket.cpp

uxsysvipc.o: uxsysvipc.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS) -c -o uxsysvipc.o uxsysvipc.cpp

uxposixipc.o: uxposixipc.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxposixipc.o uxposixipc.cpp

uxterminal.o: uxterminal.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxterminal.o uxterminal.cpp

uxnetdb.o: uxnetdb.cpp $(UXHDRS)
	$(CXX) $(CXXFLAGS)  -c -o uxnetdb.o uxnetdb.cpp

getdate_strerror.o: getdate_strerror.c
	$(CXX) $(CXXFLAGS)  -c -o getdate_strerror.o getdate_strerror.c

all:  tf

clean:
	rm  tf *.o *.so
