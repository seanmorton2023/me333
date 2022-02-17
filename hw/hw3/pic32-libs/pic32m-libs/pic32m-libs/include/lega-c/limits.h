/*
 * Copyright (c) 1996-2003 MIPS Technologies, Inc.
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
 * limits.h : machine and opertaing system limit definitions
 */


#ifndef __LIMITS_H
#define __LIMITS_H

#define CHAR_BIT 	8

#define SCHAR_MAX	0x7f
#define SCHAR_MIN 	(-0x7f-1)
#define UCHAR_MAX	0xff

#ifdef __CHAR_UNSIGNED__
#define CHAR_MAX 	0xff
#define CHAR_MIN 	0
#else
#define CHAR_MAX 	0x7f
#define CHAR_MIN 	(-0x7f-1)
#endif

#define SHRT_MAX 	0x7fff
#define SHRT_MIN 	(-0x7fff-1)
#define USHRT_MAX 	0xffff

#define INT_MAX 	0x7fffffff
#define INT_MIN 	(-0x7fffffff-1)
#define UINT_MAX 	0xffffffffU

#define LONG_MAX 	0x7fffffff
#define LONG_MIN 	(-0x7fffffff-1)
#define ULONG_MAX 	0xffffffffU

#ifndef __STRICT_ANSI__
/* GCC extension */
#define LONG_LONG_MAX	0x7fffffffffffffffLL
#define LONG_LONG_MIN	(-0x7fffffffffffffffLL-1)
#define ULONG_LONG_MAX	0xffffffffffffffffULL
#endif /* !__STRICT_ANSI__ */

#if __STDC_VERSION__ >= 199901L
/* ISO C 9X draft */
#define	LLONG_MAX	0x7fffffffffffffffLL
#define	LLONG_MIN	(-0x7fffffffffffffffLL-1)
#define	ULLONG_MAX	0xffffffffffffffffULL
#endif

#if !defined(_ANSI_SOURCE)
/* see <machine/ansi.h> for typedefs */
#define	SSIZE_MAX	LONG_MAX	/* max value for a ssize_t */
#if !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
#define	SIZE_T_MAX	ULONG_MAX	/* max value for a size_t */
#endif
#endif

/* Max length of multibyte character in any locale. */
#define MB_LEN_MAX 	16

#if defined _POSIX_SOURCE || _POSIX_C_SOURCE >= 1 || defined _XOPEN_SOURCE

/* These are fixed values defined by the POSIX standard and
   are minumums */
#define _POSIX_ARG_MAX		4096
#define _POSIX_CHILD_MAX	6
#define _POSIX_LINK_MAX		8
#define _POSIX_MAX_CANON	255
#define _POSIX_MAX_INPUT	255
#define _POSIX_NAME_MAX		14
#define _POSIX_NGROUPS_MAX	0
#define _POSIX_OPEN_MAX		16
#define	_POSIX_FD_SETSIZE	_POSIX_OPEN_MAX
#define _POSIX_PATH_MAX		255
#define _POSIX_PIPE_BUF		512
#define	_POSIX_HIWAT		_POSIX_PIPE_BUF
#define	_POSIX_TZNAME_MAX	3
#define	_POSIX_STREAM_MAX	8
#define	_POSIX_SSIZE_MAX	32767
#define _POSIX_TTY_NAME_MAX	12
#define	_POSIX_QLIMIT		1
#define	_POSIX_UIO_MAXIOV	16
#define	_POSIX_LOGIN_NAME_MAX	9
#define _POSIX_CLOCKRES_MIN	20000000

/* POSIX real-time defined minimal maximums */
#define _POSIX_AIO_LISTIO_MAX	2
#define _POSIX_AIO_MAX		1
#define _POSIX_DELAYTIMER_MAX  	32
#define _POSIX_MQ_OPEN_MAX	8
#define _POSIX_MQ_PRIO_MAX	32
#define _POSIX_RTSIG_MAX	8
#define _POSIX_SIGQUEUE_MAX	32
#define _POSIX_SEM_NSEMS_MAX	256
#define _POSIX_SEM_VALUE_MAX	32767
#define _POSIX_TIMER_MAX  	32

/* Pthread extensions */
#include <pthread/limits.h>

#endif /* defined _POSIX_SOURCE */

/* these values are set fairly arbritary to most/least restrictive values seen
 * they should be overrriden by sys/limits.h if we can do better 
 * (or even worse)
 */
#define ARG_MAX			4096
#define ATEXIT_MAX		32
#define NGROUPS_MAX		32 	/* largest */
#define OPEN_MAX		16 	/* smallest */
#define LINK_MAX		127
#define MAX_CANON		255
#define MAX_INPUT		255
#define NAME_MAX		256
#define PATH_MAX		1024
#define PIPE_BUF		4096
#define	TZNAME_MAX		3
#define	TTY_NAME_MAX		12

#include <sys/limits.h>

#endif /* !defined __LIMITS_H */
