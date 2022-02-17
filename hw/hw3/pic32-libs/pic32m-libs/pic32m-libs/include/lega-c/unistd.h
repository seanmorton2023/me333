/*
 * Copyright (c) 1996-2006 MIPS Technologies, Inc.
 * All rights reserved.
 * 
 * Unpublished rights (if any) reserved under the copyright laws of the
 * United States of America and other countries.
 * 
 * This code is proprietary to MIPS Technologies, Inc. ("MIPS
 * Technologies").  Any copying, reproducing, modifying or use of
 * this code (in whole or in part) that is not expressly permitted
 * in writing by MIPS Technologies or an authorized third party is
 * strictly prohibited.  At a minimum, this code is protected under
 * unfair competition and copyright laws.  Violations thereof may result
 * in criminal penalties and fines.
 * 
 * MIPS Technologies reserves the right to change this code to improve
 * function, design or otherwise.  MIPS Technologies does not assume any
 * liability arising out of the application or use of this code, or of
 * any error or omission in such code.  Any warranties, whether express,
 * statutory, implied or otherwise, including but not limited to the
 * implied warranties of merchantability or fitness for a particular
 * purpose, are excluded.  Except as expressly provided in any written
 * license agreement from MIPS Technologies or an authorized third party,
 * the furnishing of this code does not give recipient any license to
 * any intellectual property rights, including any patent rights, that
 * cover this code.
 * 
 * This code shall not be exported, reexported, transferred, or released,
 * directly or indirectly, in violation of the law of any country or
 * international law, regulation, treaty, Executive Order, statute,
 * amendments or supplements thereto.  Should a conflict arise regarding
 * the export, reexport, transfer, or release of this code, the laws of
 * the United States of America shall be the governing law.
 * 
 * This code constitutes one or more of the following: commercial
 * computer software, commercial computer software documentation or
 * other commercial items.  If the user of this code, or any related
 * documentation of any kind, including related technical data or
 * manuals, is an agency, department, or other entity of the United
 * States government ("Government"), the use, duplication, reproduction,
 * release, modification, disclosure, or transfer of this code, or
 * any related documentation of any kind, is restricted in accordance
 * with Federal Acquisition Regulation 12.212 for civilian agencies
 * and Defense Federal Acquisition Regulation Supplement 227.7202 for
 * military agencies.  The use of this code by the Government is further
 * restricted in accordance with the terms of the license agreement(s)
 * and/or applicable contract terms and conditions covering this code
 * from MIPS Technologies or an authorized third party.
 * 
 * 
 */

/*
 * unistd.h : POSIX definitions
 */


#ifndef __UNISTD_H
#ifdef __cplusplus
extern "C" {
#endif
#define __UNISTD_H

#ifndef __C32_LEGACY_LIBC__
#define __C32_LEGACY_LIBC__
#endif

/* --- Required -- */
#include <stddef.h>
#include <sys/types.h>
#include <sys/posix.h>

#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

/* --- For access(2) --- */
#define     R_OK     	4
#define     W_OK     	2
#define     X_OK     	1
#define     F_OK     	0

/* --- For lockf(2) --- */
#define     F_ULOCK	0
#define     F_LOCK	1
#define     F_TLOCK	2
#define     F_TEST	3

/* --- For lseek(2) --- */
#define     SEEK_SET	0
#define     SEEK_CUR	1
#define     SEEK_END	2

/* --- For sysconf() --- */
/* POSIX.1/2 */
#define _SC_ARG_MAX		1
#define _SC_ATEXIT_MAX		2
#define _SC_AVPHYS_PAGES	3
#define _SC_CHILD_MAX		4
#define _SC_CLK_TCK		5
#define _SC_FSYNC		6
#define _SC_JOB_CONTROL		7
#define _SC_NGROUPS_MAX		8
#define _SC_OPEN_MAX		9
#define _SC_PAGESIZE   		10
#define _SC_PAGE_SIZE		_SC_PAGESIZE
#define _SC_PHYS_PAGES		11
#define _SC_SAVED_IDS		12
#define _SC_STREAM_MAX		13
#define _SC_TTY_NAME_MAX	14
#define _SC_TZNAME_MAX		15
#define _SC_XOPEN_VERSION       16
#define _SC_VERSION		17
/* POSIX.4 */
#define _SC_AIO_LISTIO_MAX	(400+1)
#define _SC_AIO_MAX		(400+2)
#define _SC_AIO_PRIO_DELTA_MAX	(400+3)
#define _SC_ASYNCHRONOUS_IO	(400+4)
#define _SC_DELAYTIMER_MAX	(400+5)
#define _SC_MAPPED_FILES	(400+6)
#define _SC_MEMLOCK		(400+7)
#define _SC_MEMLOCK_RANGE	(400+8)
#define _SC_MEMLOCK_PROTECTION	(400+9)
#define _SC_MEMORY_PROTECTION	(400+10)
#define _SC_MESSAGE_PASSING	(400+11)
#define _SC_MQ_OPEN_MAX		(400+12)
#define _SC_MQ_PRIO_MAX		(400+13)
#define _SC_NPROCESSORS_CONF	(400+14)
#define _SC_NPROCESSORS_ONLN	(400+15)
#define _SC_PRIORITIZED_IO	(400+16)
#define _SC_PRIORITY_SCHEDULING	(400+17)
#define _SC_REALTIME_SIGNALS	(400+18)
#define _SC_RTSIG_MAX		(400+19)
#define _SC_SEMAPHORES		(400+20)
#define _SC_SEM_NSEMS_MAX	(400+21)
#define _SC_SEM_VALUE_MAX	(400+22)
#define _SC_SHARED_MEMORY_OBJECTS (400+23)
#define _SC_SYNCHRONIZED_IO	(400+24)
#define _SC_SIGQUEUE_MAX	(400+25)
#define _SC_TIMER_MAX		(400+26)
#define _SC_TIMERS		(400+27)

/* --- For pathconf() --- */
#define _PC_CHOWN_RESTRICTED	1
#define _PC_MAX_CANON		2
#define _PC_MAX_INPUT		3
#define _PC_NAME_MAX		4
#define _PC_NO_TRUNC		5
#define _PC_PATH_MAX		6
#define _PC_PIPE_BUF		7
#define _PC_VDISABLE		8
#define _PC_LINK_MAX		9
/* POSIX.4 */
#define _PC_ASYNC_IO		10
#define _PC_PRIO_IO		11
#define _PC_SYNC_IO		12

/* --- Prototypes --- */
  /* --- Process creation and execution --- */
pid_t	fork(void);
int	execl(const char *, const char *, ...);
int	execv(const char *, const char * const *);
int	execle(const char *, const char *, ...);
int	execve(const char *, const char * const *, const char * const *);
int	execlp(const char *, const char *, ...);
int	execvp(const char *, const char * const *);
int	profil(char *, int, int, int);

  /* --- MIPS special --- */
int	spawn (const char *, int (*)(int, char **), int, char **);

  /* --- Process termination --- */
void	_exit(int) __attribute__ ((noreturn));

  /* --- Timer operations --- */
unsigned int alarm(unsigned int);
int	pause(void);
unsigned int sleep(unsigned int);
unsigned int usleep(unsigned int);

  /* --- Process identification --- */
pid_t	getpid(void);
pid_t	getppid(void);

  /* --- User identification --- */
uid_t	getuid(void);
uid_t	geteuid(void);
gid_t	getgid(void);
gid_t	getegid(void);
int	setuid(uid_t);
int	setgid(gid_t);
int	getgroups(int, gid_t []);
char	*getlogin(void);
char	*cuserid(char *);

  /* --- Process groups --- */
pid_t	getpgid(pid_t);
pid_t	getpgrp(void);
int	setpgid(pid_t, pid_t);
int	setpgrp(void);

  /* --- Sessions --- */
pid_t	setsid(void);

  /* --- Terminal identification --- */
char	*ttyname(int);
int	ttyname_r(int, char *, size_t);
int	isatty(int);

  /* --- Configurable system variables --- */
long	sysconf(int);

  /* --- Working directory --- */
int	chdir(const char *);
char	*getcwd(char *, size_t);

  /* --- General file creation --- */
int	link(const char *, const char *);

  /* --- File removal --- */
int	unlink(const char *);
int	rmdir(const char *);

  /* --- File characteristics --- */
int	access(const char *, int);
int	chown(const char *, uid_t, gid_t);

  /* --- Configurable pathname variables --- */
long	pathconf(const char *, int);
long	fpathconf(int fd, int);

  /* --- Pipes --- */
int	pipe(int [2]);

  /* --- File descriptor manipulation  POSIX, use fcntl --- */
int	dup(int);
int	dup2(int, int);

  /* --- File descriptor deassignment --- */
int	close(int);

  /* --- Input and output --- */
ssize_t	read(int, void  *, size_t);
ssize_t	write(int fd, const void *, size_t);

  /* --- Control operations on files --- */
off_t	lseek(int, off_t, int);

  /* --- General terminal interface control --- */
pid_t	tcgetpgrp(int);
int	tcsetpgrp(int, pid_t);

#ifndef _POSIX_SOURCE
  /* --- Memory allocation --- */
void	*_sbrk (int);
void	*sbrk (int);
int	getpagesize (void);

  /* --- File handling --- */
int	fchdir(int);
int	fchown(int, uid_t, gid_t);
int	fsync(int);
int	ftruncate(int, off_t);
int	getdtablesize(void);
int	lchown(const char *, uid_t, gid_t);

  /* --- File i/o */
#ifndef _XOPEN_SOURCE
struct timeval;
int	select (int, fd_set *, fd_set *, fd_set *, struct timeval *);
#endif

  /* --- Network system calls */
int	getdomainname (char *, size_t);
int	gethostid (void);
int	gethostname (char *, size_t);
int     issetugid (void);

  /* --- Network library functions */
int     rresvport (int *);
int     rresvport_af (int *, int);

#if (!defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE)) || \
    (_XOPEN_SOURCE - 0) >= 500
  /* -- Unix98 -- */
ssize_t	pread(int, void  *, size_t, off_t);
ssize_t	pwrite(int fd, const void *, size_t, off_t);
#endif

  /* --- Messaging utilities --- */
void	psignal(unsigned int, const char *);
extern const char * const sys_siglist[];
extern const char * const sys_signame[];
#endif

  /* --- Argument parsing */
#if !defined(_ANSI_SOURCE) || defined(_POSIX_SOURCE)
#include <libc_thread.h>
int getopt (int, char *const *, const char *);
#endif

#ifdef __cplusplus
}
#endif
#endif /* !defined __UNISTD_H */
