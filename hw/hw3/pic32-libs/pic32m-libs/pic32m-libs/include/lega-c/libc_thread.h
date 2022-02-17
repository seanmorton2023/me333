/*
 * Copyright (c) 2001-2006 MIPS Technologies, Inc.
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
 * libc_thread.h: per-thread and per-process support
 */


#ifndef __LIBC_THREAD_H__
#define __LIBC_THREAD_H__

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This variable is initally 0 when there is exactly one thread.
 * It should never decrease.
 */
extern int __isthreaded;

/*
 * Use WEAK_NAME(n) to get a libc-private name for n (_weak_n),
 *     WEAK_ALIAS(n) to generate the weak symbol n pointing to _weak_n,
 *     WEAK_PROTOTYPE(n) to generate a prototype for _weak_n (based on n).
 */

#if defined(__STDC__) || defined(__cplusplus)
#define WEAK_NAME(name)			_weak_ ## name
#else
#define WEAK_NAME(name)			_weak_/**/name
#endif
#define WEAK_ALIAS(name)		__weak_alias(name, WEAK_NAME(name))
#define WEAK_PROTOTYPE(name)		__typeof__(name) WEAK_NAME(name)


/*
 * These macros help in making persistent storage thread-specific.
 * Libc makes extensive use of private static data structures
 * that hold state across function invocation, and these macros
 * are no-ops when running single-threaded.
 *
 * Linking against the user-thread library causes these macros to
 * allocate storage on a per-thread basis.
 */
	
#if defined(__STDC__) || defined(__cplusplus)
#define __THREAD_KEY_NAME(name)		_libc_storage_key_ ## name
#else
#define __THREAD_KEY_NAME(name)		_libc_storage_key_/**/name
#endif

struct _thread_private_key_struct {
	pthread_mutex_t		mutex;
	int			inited;
	void			(*cleanfn)(void *);
	pthread_key_t		key;
};

/* Declare a thread-private storage key. */
#define _THREAD_PRIVATE_KEY(name)					\
	static struct _thread_private_key_struct			\
	__THREAD_KEY_NAME(name) = {					\
		PTHREAD_MUTEX_INITIALIZER,				\
		0,							\
		NULL,							\
		0							\
	}

/* Declare a thread-private storage key with cleanup. */
#define _THREAD_PRIVATE_KEY_CLEANUP(name,cleanfn)			\
	static struct _thread_private_key_struct			\
	__THREAD_KEY_NAME(name) = {					\
		PTHREAD_MUTEX_INITIALIZER,				\
		0,							\
		cleanfn,						\
		0							\
	}

/*
 * In threaded mode, return a pointer to thread-private memory of
 * the same size as, and (initially) with the same contents as 'storage'. If
 * an error occurs, the 'error' parameter is returned.
 * In single-threaded mode, no storage is allocated. Instead, a pointer
 * to storage is always returned.
 * The 'cleanfn' function of the key structure is called to free the storage.
 * If 'cleanfn' is NULL, then free() is used. This hook can be useful for
 * getting rid of memory leaks.
 */
#define _THREAD_PRIVATE(keyname, storage, error) 			\
	_libc_private_storage(&__THREAD_KEY_NAME(keyname),		\
		&(storage), sizeof (storage), error)

void *	_libc_private_storage(struct _thread_private_key_struct *,
			      void *, size_t, void *);
		
/* 
 * One of these structures exists for each "process" level thread, and
 * allows each process to have its own set of file handles and other
 * important data.
 */
struct _libc_data {
    struct _iob *	_stdin;
    struct _iob *	_stdout;
    struct _iob *	_stderr;
    struct _iov *	_iov;
    struct _atexit *	_atexit;
    int			_opterr;
    int			_optind;
    int			_optopt;
    int			_optreset;
    char *		_optarg;
    char *		_optplace;
    int			_tmpnamsuf;
    void *		_malloc;
    void 		(*_cleanup) (void);
    int			_exiting;
    int			_ieee754csr;
    int			_spare[8];
};

extern struct _libc_data *	_libc_data;

/* user-visible symbols */
#define stdin		(_libc_data->_stdin)
#define stdout		(_libc_data->_stdout)
#define stderr		(_libc_data->_stderr)
#define ieee754csr	(*(struct ieee754csr *)(&_libc_data->_ieee754csr))

#ifdef __cplusplus
}
#endif
#endif /* __LIBC_THREAD_H__ */
