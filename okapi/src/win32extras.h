
#ifndef _WIN32EXTRAS_H
#define _WIN32EXTRAS_H

#define _X86_
#include <time.h>
#include <sys/timeb.h>
#include <float.h>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <windows.h>

////////////////////////////////////////////////////////////////////////////////
// Numerical functions mapped from UNIX -> WIN32
////////////////////////////////////////////////////////////////////////////////

#define isnan(x) _isnan(x)

////////////////////////////////////////////////////////////////////////////////
// String functions mapped from UNIX -> WIN32
////////////////////////////////////////////////////////////////////////////////

#define strcasecmp(x, y) _stricmp(x, y)
#define strncasecmp(x, y, z) _strnicmp(x, y, z)

////////////////////////////////////////////////////////////////////////////////
// Memory Allocation functions mapped from UNIX -> WIN32
////////////////////////////////////////////////////////////////////////////////

#define alloca(size) _alloca(size)

////////////////////////////////////////////////////////////////////////////////
// File/Stream Access functions mapped from UNIX -> WIN32
////////////////////////////////////////////////////////////////////////////////

#define ftello(x) ftell(x);
#define read _read
#define lseek _lseeki64
#define open _open
#define getenv GetSetting
#define L_cuserid 32

////////////////////////////////////////////////////////////////////////////////
// Named typedefs from UNIX usually found in sys/types.h
// They are not implemented on Win32
////////////////////////////////////////////////////////////////////////////////

typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned int		u_int;
typedef int					ssize_t;
typedef long				time_t;

////////////////////////////////////////////////////////////////////////////////
// User/Group related structures and defines
////////////////////////////////////////////////////////////////////////////////

typedef int					uid_t;
typedef uid_t				gid_t;

////////////////////////////////////////////////////////////////////////////////
// These structures are normally implemented withinn BSD time functions
// on UNIX in sys/time.h.  They are not implemented on WIN32
////////////////////////////////////////////////////////////////////////////////

struct timezone 
{
	int		tz_minuteswest;		/* minutes west of Greenwich */
	int		tz_dsttime;			/* type of dst correction */
};

////////////////////////////////////////////////////////////////////////////////
// Process Information Mapping types
////////////////////////////////////////////////////////////////////////////////

typedef long pid_t;

////////////////////////////////////////////////////////////////////////////////
// The following functions do not exist on WIN32 and have been written as 
// wrappers to provide the missing functionality using native win32 calls
////////////////////////////////////////////////////////////////////////////////

int gettimeofday(struct timeval *tp, void *tz);

pid_t getpid(void);
uid_t getuid(void);
gid_t getgid(void);

int getgroups(int gidsetsize, gid_t *grouplist);

char * cuserid(char *s);

int ftruncate(int fildes, off_t length);

////////////////////////////////////////////////////////////////////////////////
// Programs Settings (Usually held in Environment Vars
// These settings now come from the registry
////////////////////////////////////////////////////////////////////////////////

#define BSS_REG_BASE_KEY	HKEY_CURRENT_USER
#define BSS_REG_PATH		"Software\\Microsoft\\BSS\\"

////////////////////////////////////////////////////////////////////////////////
// Registry Access Functions
////////////////////////////////////////////////////////////////////////////////

BYTE* GetSetting(LPCSTR strSettingName);


////////////////////////////////////////////////////////////////////////////////
// List of Environment Variables which have been mapped to registry entries
////////////////////////////////////////////////////////////////////////////////

// BSS
// BSS_ATTRIBUTE	
// BSS_BIBPATH
// BSS_COMBINE_DO_STATS
// BSS_DB
// BSS_DB_FLAGS
// BSS_DEBUG
// BSS_LIMIT
// BSS_LOCALBIBPATH
// BSS_LOGDIR
// BSS_PARMPATH
// BSS_PASSAGE_AVEDOCLEN
// BSS_PASSAGE_MAXITERS
// BSS_PASSAGE_THRESH_DOCLEN
// BSS_SEARCHPROG
// BSS_TEMPPATH
// BSS_WT_PWR
// OKAPI 

////////////////////////////////////////////////////////////////////////////////
// BEGIN : Unused defines and structure mappings
////////////////////////////////////////////////////////////////////////////////

/*

#define lseek(handle, offset, origin) _lseeki64(handle, offset, origin);
#define read(handle, buffer, count) _read(handle, buffer, count);
#define open(filename, oflag) _open(filename, oflag);
#define open(filename, oflag, pmode) _open(filename, oflag, pmode);
#define fseeko(stream, offset, origin) fseek(stream, offset, origin)

typedef __int64				off_t; 

struct timeval 
{
	long	tv_sec;				// seconds
	long	tv_usec;			// and microseconds
};

*/

////////////////////////////////////////////////////////////////////////////////
// END : Unused defines and structure mappings
////////////////////////////////////////////////////////////////////////////////

#endif /* _WIN32EXTRAS_H */
