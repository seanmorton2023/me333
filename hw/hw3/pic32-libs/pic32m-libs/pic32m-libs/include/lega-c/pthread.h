/*
 * Copyright (c) 1996-2004 MIPS Technologies, Inc.
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
 * pthread.h: POSIX threads definitions
 */


#ifndef __PTHREAD_H
#define __PTHREAD_H

#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>
#include <sched.h>

/*#include <rtpx.h>*/
#include <pthread/impl.h>
#include <pthread/unistd.h>
#include <pthread/limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __C32_LEGACY_LIBC__
#define __C32_LEGACY_LIBC__
#endif


/* just make sure */
#if defined(_POSIX_THREAD_PRIO_INHERIT) 
#if !defined(_POSIX_THREAD_PRIORITY_SCHEDULING)
#error _POSIX_THREAD_PRIO_INHERIT
#endif
#endif

#if defined(_POSIX_THREAD_PRIO_PROTECT) 
#if !defined(_POSIX_THREAD_PRIORITY_SCHEDULING)
#error _POSIX_THREAD_PRIO_PROTECT
#endif
#endif

#if defined(_POSIX_THREAD_PRIORITY_SCHEDULING)
#if !defined(_POSIX_THREADS)
#error _POSIX_THREAD_PRIORITY_SCHEDULING
#endif
#endif

#if defined(_POSIX_THREADS)
#if !defined(_POSIX_THREAD_SAFE_FUNCTIONS)
#error _POSIX_THREADS
#endif
#endif


/* thread detachstate values */
enum {
    PTHREAD_CREATE_JOINABLE,
#define PTHREAD_CREATE_JOINABLE	PTHREAD_CREATE_JOINABLE
    PTHREAD_CREATE_DETACHED,
#define PTHREAD_CREATE_DETACHED	PTHREAD_CREATE_DETACHED
    PTHREAD_CREATE_DAEMON_NP
#define PTHREAD_CREATE_DAEMON_NP PTHREAD_CREATE_DAEMON_NP
};

/* thread scope values */
enum {
    PTHREAD_SCOPE_PROCESS,
#define PTHREAD_SCOPE_PROCESS	PTHREAD_SCOPE_PROCESS
    PTHREAD_SCOPE_SYSTEM
#define PTHREAD_SCOPE_SYSTEM	PTHREAD_SCOPE_SYSTEM
};

/* thread sched type values */
enum {
    PTHREAD_INHERIT_SCHED,
#define PTHREAD_INHERIT_SCHED	PTHREAD_INHERIT_SCHED
    PTHREAD_EXPLICIT_SCHED
#define PTHREAD_EXPLICIT_SCHED	PTHREAD_EXPLICIT_SCHED
};

/* thread attributes */
typedef struct {
    void *		tha_stackaddr;
    unsigned int 	tha_stacksize;
    unsigned int 	tha_guardsize;
    unsigned char	tha_detachstate;
    unsigned char	tha_scope;
    unsigned char	tha_inheritsched;
    unsigned char	tha_schedpolicy;
    struct sched_param	tha_schedparam;
    const char * 	tha_name;
} pthread_attr_t;


/* mutex priority protection values */
enum {
    PTHREAD_PRIO_NONE,
#define PTHREAD_PRIO_NONE	PTHREAD_PRIO_NONE
    PTHREAD_PRIO_INHERIT,
#define PTHREAD_PRIO_INHERIT	PTHREAD_PRIO_INHERIT
    PTHREAD_PRIO_PROTECT
#define PTHREAD_PRIO_PROTECT	PTHREAD_PRIO_PROTECT
};

/* mutex pshared values */
enum {
    PTHREAD_PROCESS_PRIVATE,
#define PTHREAD_PROCESS_PRIVATE	PTHREAD_PROCESS_PRIVATE
    PTHREAD_PROCESS_SHARED
#define PTHREAD_PROCESS_SHARED	PTHREAD_PROCESS_SHARED
};


/* mutex type values */
enum
{
  PTHREAD_MUTEX_DEFAULT_NP,
  PTHREAD_MUTEX_FAST_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP
#if (_XOPEN_SOURCE - 0) >= 500
  ,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_DEFAULT_NP,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_FAST_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP
#endif
};


typedef struct {
    unsigned char	mxa_type;
    unsigned char	mxa_pshared;
    unsigned char	mxa_protocol;
    unsigned char	mxa_prioceiling;
    const char * 	mxa_name;
} pthread_mutexattr_t;


typedef struct {
    unsigned char	cda_pshared;
    unsigned char	cda_interruptible;
    const char * 	cda_name;
} pthread_condattr_t;


typedef struct {
    unsigned char	rwa_pshared;
    const char * 	rwa_name;
} pthread_rwlockattr_t;


/* 
 * THREAD ATTRIBUTES 
 */
int pthread_attr_init (pthread_attr_t *);
int pthread_attr_destroy (pthread_attr_t *);
int pthread_attr_setscope (pthread_attr_t *, int);
int pthread_attr_getscope (const pthread_attr_t *, int *);
int pthread_attr_setinheritsched (pthread_attr_t *, int);
int pthread_attr_getinheritsched (const pthread_attr_t *, int *);
int pthread_attr_setschedpolicy (pthread_attr_t *, int);
int pthread_attr_getschedpolicy (const pthread_attr_t *, int *);
int pthread_attr_setschedparam (pthread_attr_t *, const struct sched_param *);
int pthread_attr_getschedparam (const pthread_attr_t *, struct sched_param *);
int pthread_attr_setcontentionscope (pthread_attr_t *, int);
int pthread_attr_getcontentionscope (const pthread_attr_t *, int *);
int pthread_attr_setstacksize (pthread_attr_t *, size_t);
int pthread_attr_getstacksize (const pthread_attr_t *, size_t *);
int pthread_attr_setstackaddr (pthread_attr_t *, void *);
int pthread_attr_getstackaddr (const pthread_attr_t *, void **);
int pthread_attr_setguardsize_np (pthread_attr_t *, size_t);
int pthread_attr_getguardsize_np (const pthread_attr_t *, size_t *);
#if (_XOPEN_SOURCE - 0) >= 500
#define pthread_attr_setguardsize pthread_attr_setguardsize_np
#define pthread_attr_getguardsize pthread_attr_getguardsize_np
#endif
int pthread_attr_setdetachstate (pthread_attr_t *, int);
int pthread_attr_getdetachstate (const pthread_attr_t *, int *);
int pthread_attr_setprio (pthread_attr_t *, int);
int pthread_attr_getprio (const pthread_attr_t *, int *);
#ifdef _POSIX_THREAD_ATTR_NAME_NP
int pthread_attr_setname_np (pthread_attr_t *, const char *);
int pthread_attr_getname_np (const pthread_attr_t *, const char **);
#endif


/* 
 * MUTEX ATTRIBUTES
 */
int pthread_mutexattr_init (pthread_mutexattr_t *);
int pthread_mutexattr_destroy (pthread_mutexattr_t *);
int pthread_mutexattr_setpshared (pthread_mutexattr_t *, int);
int pthread_mutexattr_getpshared (const pthread_mutexattr_t *, int *);
#if defined(_POSIX_THREAD_PRIO_PROTECT) \
   || defined(_POSIX_THREAD_PRIO_INHERIT)
int pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int);
int pthread_mutexattr_getprotocol (const pthread_mutexattr_t *, int *);
#endif
#ifdef _POSIX_THREAD_PRIO_PROTECT
int pthread_mutexattr_setprioceiling (pthread_mutexattr_t *, int);
int pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *, int *);
#endif
#ifdef _POSIX_THREAD_ATTR_NAME_NP
int pthread_mutexattr_setname_np (pthread_mutexattr_t *, const char *);
int pthread_mutexattr_getname_np (const pthread_mutexattr_t *, const char **);
#endif
#ifdef _POSIX_THREAD_MUTEX_TYPE_NP
int pthread_mutexattr_settype_np (pthread_mutexattr_t *, int);
int pthread_mutexattr_gettype_np (const pthread_mutexattr_t *, int *);
#if (_XOPEN_SOURCE - 0) >= 500
#define pthread_mutexattr_settype	pthread_mutexattr_settype_np
#define pthread_mutexattr_gettype	pthread_mutexattr_gettype_np
#endif
#endif

/* 
 * CONDITION ATTRIBUTES 
 */
int pthread_condattr_init (pthread_condattr_t *);
int pthread_condattr_destroy (pthread_condattr_t *);
int pthread_condattr_setpshared (pthread_condattr_t *, int);
int pthread_condattr_getpshared (const pthread_condattr_t *, int *);
#ifdef _POSIX_THREAD_ATTR_NAME_NP
int pthread_condattr_setname_np (pthread_condattr_t *, const char *);
int pthread_condattr_getname_np (const pthread_condattr_t *, const char **);
#endif
int pthread_condattr_setinterruptible_np (pthread_condattr_t *, int);
int pthread_condattr_getinterruptible_np (const pthread_condattr_t *, int *);


/* 
 * RWLOCK ATTRIBUTES
 */
int pthread_rwlockattr_init (pthread_rwlockattr_t *);
int pthread_rwlockattr_destroy (pthread_rwlockattr_t *);
int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *, int);
int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *, int *);

/*
 * MUTEXES
 */

typedef struct pthread_mutex {
  _pthread_waitq_t	mx_waitq;
  unsigned int		mx_flags;	/* internal flags */
  pthread_mutexattr_t	mx_mxa;		/* attributes */
  pthread_t		mx_owner;	/* mutex owner */
  struct pthread_mutex	*mx_olink;	/* other mutexes owned */
  short			mx_count;	/* recursion count */
  char			mx_spare[6];	/* for expansion */
} pthread_mutex_t;

#define PTHREAD_MUTEX_INITIALIZER \
  {{0},~0, \
   {PTHREAD_MUTEX_DEFAULT_NP, PTHREAD_PROCESS_PRIVATE, PTHREAD_PRIO_NONE, 0, 0}, \
   0, 0, 0, {}}

#define PTHREAD_FAST_MUTEX_INITIALIZER_NP \
  {{0},~0, \
   {PTHREAD_MUTEX_FAST_NP, PTHREAD_PROCESS_PRIVATE, PTHREAD_PRIO_NONE, 0, 0}, \
   0, 0, 0, {}}

#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
  {{0},~0, \
   {PTHREAD_MUTEX_RECURSIVE_NP, PTHREAD_PROCESS_PRIVATE, PTHREAD_PRIO_NONE, 0, 0}, \
   0, 0, 0, {}}

#define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
  {{0},~0, \
   {PTHREAD_MUTEX_ERRORCHECK_NP, PTHREAD_PROCESS_PRIVATE, PTHREAD_PRIO_NONE, 0, 0}, \
   0, 0, 0, {}}

#if (_XOPEN_SOURCE - 0) >= 500
#define PTHREAD_NORMAL_MUTEX_INITIALIZER \
  PTHREAD_FAST_MUTEX_INITIALIZER_NP
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER \
  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
#define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER \
  PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP
#endif

int pthread_mutex_init (pthread_mutex_t *, const pthread_mutexattr_t *);
int pthread_mutex_destroy (pthread_mutex_t *);
int pthread_mutex_lock (pthread_mutex_t *);
int pthread_mutex_trylock (pthread_mutex_t *);
int pthread_mutex_unlock (pthread_mutex_t *);
int pthread_mutex_setprioceiling (pthread_mutex_t *, int, int *);
int pthread_mutex_getprioceiling (const pthread_mutex_t *, int *);
#ifdef _POSIX_THREAD_ATTR_NAME_NP
int pthread_mutex_setname_np (pthread_mutex_t *, const char *);
int pthread_mutex_getname_np (const pthread_mutex_t *, const char **);
#endif


/*
 * CONDITION VARIABLES
 */
typedef struct {
  _pthread_waitq_t	cd_waitq;
  pthread_condattr_t	cd_cda;
  char			cd_spare[8];	/* for expansion */
} pthread_cond_t;

#define PTHREAD_COND_INITIALIZER {{0},{0},{}}

struct timespec;
int pthread_cond_init (pthread_cond_t *, const pthread_condattr_t *);
int pthread_cond_destroy (pthread_cond_t *);
int pthread_cond_wait (pthread_cond_t *, pthread_mutex_t *);
int pthread_cond_timedwait (pthread_cond_t *, pthread_mutex_t *,
			    const struct timespec *);
int pthread_cond_signal (pthread_cond_t *);
int pthread_cond_broadcast (pthread_cond_t *);
#ifdef _POSIX_THREAD_ATTR_NAME_NP
int pthread_cond_setname_np (pthread_cond_t *, const char *);
int pthread_cond_getname_np (const pthread_cond_t *, const char **);
#endif


/*
 * READ/WRITE LOCKS
 */
typedef struct {
    pthread_mutex_t	rw_mx;
    pthread_cond_t	rw_rsig;
    pthread_cond_t	rw_wsig;
    pthread_rwlockattr_t rw_rwa;
    int			rw_locks;	/* +ve = # readers, -1 = writer */
    int			rw_wrwait;	/* # waiting for write lock */
    int			rw_rdwait;	/* # waiting for read lock */
    pthread_t		rw_owner;	/* owner of write lock */
} pthread_rwlock_t;

#define PTHREAD_RWLOCK_INITIALIZER { 	\
    PTHREAD_MUTEX_INITIALIZER, 		\
    PTHREAD_COND_INITIALIZER,		\
    PTHREAD_COND_INITIALIZER,		\
    {0, 0},				\
    0, 0, 0, 0				\
}

int pthread_rwlock_init (pthread_rwlock_t *, const pthread_rwlockattr_t *);
int pthread_rwlock_destroy (pthread_rwlock_t *);
int pthread_rwlock_rdlock (pthread_rwlock_t *);
int pthread_rwlock_wrlock (pthread_rwlock_t *);
int pthread_rwlock_tryrdlock (pthread_rwlock_t *);
int pthread_rwlock_trywrlock (pthread_rwlock_t *);
int pthread_rwlock_unlock (pthread_rwlock_t *);

/*
 * THREAD CONTROL 
 */
int pthread_create (pthread_t *, const pthread_attr_t *,
		    void * (*)(void *), void *);
void pthread_exit (void *) __attribute__ ((noreturn));
int pthread_sigmask (int, const sigset_t *, sigset_t *);
int pthread_kill (pthread_t, int);
pthread_t pthread_self (void);

#define PTHREAD_CANCELED ((void *)-1)
int pthread_join (pthread_t, void **);
int pthread_detach (pthread_t);

#define pthread_equal(a, b)	((a) == (b))
int (pthread_equal) (pthread_t, pthread_t);

int pthread_getschedparam (pthread_t, int *, struct sched_param *);
int pthread_setschedparam (pthread_t, int, const struct sched_param *);

int pthread_getconcurrency_np (void);
int pthread_setconcurrency_np (int);
#if (_XOPEN_SOURCE - 0) >= 500
#define pthread_getconcurrency	pthread_getconcurrency_np
#define pthread_setconcurrency	pthread_setconcurrency_np
#endif

/*
 * ONCE HANDLING
 */
typedef struct {
    unsigned int 	state;
} pthread_once_t;

#define PTHREAD_ONCE_NEVER	0
#define PTHREAD_ONCE_INPROGRESS	1
#define PTHREAD_ONCE_DONE	2
#define PTHREAD_ONCE_INIT 	{ PTHREAD_ONCE_NEVER }

int _pthread_once (pthread_once_t *, void (*)(void));
int (pthread_once) (pthread_once_t *, void (*)(void));
#ifdef __OPTIMIZE__
#define pthread_once(once, func) \
  ((once)->state == PTHREAD_ONCE_DONE ? 0 : _pthread_once (once, func))
#endif

/*
 * CANCELLATION 
 */
int pthread_cancel (pthread_t);
void pthread_testcancel (void);
#define PTHREAD_CANCEL_ENABLE	0x00
#define PTHREAD_CANCEL_DISABLE	0x01
int pthread_setcancelstate (int, int *);
#define PTHREAD_CANCEL_ASYNCHRONOUS	0x00
#define PTHREAD_CANCEL_DEFERRED		0x02
int pthread_setcanceltype (int, int *);

#ifdef _POSIX_THREAD_ATTR_NAME_NP
int pthread_setname_np (pthread_t, const char *);
int pthread_getname_np (pthread_t, const char **);
#endif

int pthread_getsequence_np (pthread_t, int *);
int pthread_stackused_np (pthread_t, int *);


/* 
 * THREAD-SPECIFIC DATA 
 */
typedef size_t pthread_key_t;
int pthread_key_create (pthread_key_t *, void (*)(void *));
int pthread_key_delete (pthread_key_t);
int pthread_setspecific (pthread_key_t, const void *);
/* XXX could be implemented as a macro */
void * (pthread_getspecific) (pthread_key_t);

/*
 * CLEANUP HANDLING
 */
struct _pthread_handler_rec {
    struct _pthread_handler_rec *next;
    void	(*rtn)(void *);
    void	*arg;
    int		canceltype;
};

void _pthread_cleanup_push (struct _pthread_handler_rec *);
void _pthread_cleanup_pop (struct _pthread_handler_rec *);

void _pthread_cleanup_push_defer (struct _pthread_handler_rec *);
void _pthread_cleanup_pop_restore (struct _pthread_handler_rec *);

#define pthread_cleanup_push(func,argp) { \
	struct _pthread_handler_rec __cleanup_handler; \
	__cleanup_handler.rtn = func; \
	__cleanup_handler.arg = argp; \
	_pthread_cleanup_push (&__cleanup_handler); \

#define pthread_cleanup_pop(ex) \
	_pthread_cleanup_pop (&__cleanup_handler); \
	if (ex) (*__cleanup_handler.rtn)(__cleanup_handler.arg); \
	}

#define pthread_cleanup_push_defer_np(func,argp) { \
	struct _pthread_handler_rec __cleanup_handler; \
	__cleanup_handler.rtn = func; \
	__cleanup_handler.arg = argp; \
	_pthread_cleanup_push_defer (&__cleanup_handler); \

#define pthread_cleanup_pop_restore_np(ex) \
	_pthread_cleanup_pop_restore (&__cleanup_handler); \
	if (ex) (*__cleanup_handler.rtn)(__cleanup_handler.arg); \
	}

#ifdef _POSIX_THREAD_DOORBELL_NP
/* 
 * HARDWARE DOORBELLS 
 */
typedef struct {
    int			dba_evn;
    const char *	dba_name;
} pthread_doorbellattr_t;

typedef struct {
  _pthread_waitq_t		db_waitq;
  pthread_doorbellattr_t	db_dba;
  char 				db_spare[8];	/* for expansion */
} pthread_doorbell_t;

#define PTHREAD_DOORBELL_INITIALIZER(evn) \
    {{0}, {evn}, {}}

int pthread_doorbellattr_init (pthread_doorbellattr_t *);
int pthread_doorbellattr_destroy (pthread_doorbellattr_t *);
int pthread_doorbellattr_setevn (pthread_doorbellattr_t *, int);
int pthread_doorbellattr_getevn (const pthread_doorbellattr_t *, int *);
int pthread_doorbellattr_setname (pthread_doorbellattr_t *, const char *);
int pthread_doorbellattr_getname (const pthread_doorbellattr_t *, const char **);

int pthread_doorbell_init (pthread_doorbell_t *, 
			   const pthread_doorbellattr_t *);
int pthread_doorbell_destroy (pthread_doorbell_t *);
int pthread_doorbell_wait (pthread_doorbell_t *, pthread_mutex_t *);
int pthread_doorbell_trywait (pthread_doorbell_t *);
int pthread_doorbell_timedwait (pthread_doorbell_t *, pthread_mutex_t *,
				struct timespec *);
#endif /* _POSIX_THREAD_DOORBELL_NP */

/* REENTRANT FILE LOCK */
typedef struct {
    pthread_mutex_t	mx;
    pthread_t		owner;
    unsigned int	nlock;
    pthread_cond_t	notbusy;
    char		name[8];
} pthread_flock_np_t;

void pthread_flock_init_np (pthread_flock_np_t *, const char *, int, int);
int pthread_flock_lock_np (pthread_flock_np_t *);
int pthread_flock_trylock_np (pthread_flock_np_t *);
void pthread_flock_unlock_np (pthread_flock_np_t *);
void pthread_flock_cleanup_np (pthread_flock_np_t *);

/* SIGNAL/CANCELLATION */
typedef struct {
    sigset_t		omask;
    sigset_t		odefer;
    int			cancel;
} pthread_sigstate_np_t;

void pthread_sigdisable_np (pthread_sigstate_np_t *);
void pthread_sigrestore_np (const pthread_sigstate_np_t *);
int pthread_sigdeferred_np (void);

/* PTHREAD-SPECIFIC sysconf() */
long pthread_sysconf_np (int);

/* PTHREAD-SPECIFIC MEMORY ALLOCATION */
void * pthread_getpages_np (size_t);

/* PTHREAD-SPECIFIC PROCESS CONTROL */
/* XXX pid_t may not be defined */
int pthread_proc_create_np (int *, const pthread_attr_t *, 
			    int (*)(void *), void *);

#ifdef __cplusplus
}
#endif

#endif /* __PTHREAD_H */
