/*
 * Copyright (c) 2000-2003 MIPS Technologies, Inc.
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
 * pthread/unistd.h : POSIX Threads definitions
 */


#ifndef __PTHREAD_UNISTD_H
#define __PTHREAD_UNISTD_H

#define _POSIX_THREADS
#define _POSIX_THREAD_ATTR_STACKSIZE
#define _POSIX_THREAD_ATTR_STACKADDR
#define _POSIX_THREAD_PRIORITY_SCHEDULING
#define _POSIX_THREAD_PRIO_PROTECT
#define _POSIX_THREAD_PRIO_INHERIT
#define	_POSIX_THREAD_SAFE_FUNCTIONS
#undef	_POSIX_THREAD_PROCESS_SHARED

/* extra "non-posix" functions */
#define _POSIX_THREAD_MUTEX_TYPE_NP
#define _POSIX_THREAD_ATTR_NAME_NP
#define _POSIX_THREAD_DOORBELL_NP

/* These are POSIX.4 but we implement them too */
#define _POSIX_TIMERS
#define _POSIX_SEMAPHORES
#define _POSIX_MESSAGE_PASSING
#define _POSIX_REALTIME_SIGNALS

/* For sysconf() */
#define _SC_THREADS			(300+1)
#define _SC_THREAD_SAFE_FUNCTIONS	(300+2)
#define _SC_THREAD_THREADS_MAX		(300+3)
#define _SC_THREAD_ATTR_STACKADDR	(300+4)
#define _SC_THREAD_ATTR_STACKSIZE	(300+5)
#define _SC_THREAD_PROCESS_SHARED	(300+6)
#define _SC_THREAD_PRIORITY_SCHEDULING	(300+7)
#define _SC_THREAD_DESTRUCTOR_ITERATIONS (300+8)
#define _SC_THREAD_STACK_MIN		(300+9)
#define _SC_THREAD_PRIO_INHERIT		(300+10)
#define _SC_THREAD_PRIO_PROTECT		(300+11)
#define _SC_THREAD_KEYS_MAX		(300+12)

#endif /* __PTHREAD_UNISTD_H */
