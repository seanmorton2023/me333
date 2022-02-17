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
 * stdlib.h : ANSI stdlib definitions
 */


#ifndef __STDLIB_H
#ifdef __cplusplus
extern "C" {
#endif
#define __STDLIB_H

#ifndef __C32_LEGACY_LIBC__
#define __C32_LEGACY_LIBC__
#endif

/* 
 * This is a ANSI-C header file only
*/

/* --- Inclusions --- */
#include <stddef.h>		/* wrong -- offsetof again */

/* --- Constants --- */
#define RAND_MAX	0x7fffffff

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

#if defined(__STRICT_ANSI__)
#define __INLINE
#else
#define __INLINE inline __attribute__((always_inline))
#endif

typedef struct {int quot; int rem;} div_t;
typedef struct {long int quot; long int rem;} ldiv_t;
#ifndef __STRICT_ANSI__
typedef struct {long long int quot; long long int rem;} lldiv_t;
#endif


int	atoi	(const char *);
long	atol	(const char *);
long	strtol	(const char *, char **, int);
unsigned long strtoul (const char *, char **, int);
#ifndef __STRICT_ANSI__
long long atoll	(const char *);
long long strtoll (const char *, char **, int);
unsigned long long strtoull (const char *, char **, int);
#endif

#if (__DBL_MANT_DIG__ == __FLT_MANT_DIG__) && !defined(__FDLMATH_XDOUBLE)
#define __FDLMATH_XDOUBLE long double
#else
#define __FDLMATH_XDOUBLE double
#endif

#if defined(__mips_hard_float)

extern __FDLMATH_XDOUBLE strtod (const char *, char **);
#ifndef __STRICT_ANSI__
extern float strtof (const char *, char **);
#endif /* __STRICT_ANSI__ */

#else /* !defined(__mips_hard_float) */

extern __FDLMATH_XDOUBLE __strtod(const char *, char **);
#if !defined(__LIBBUILD__)
static __INLINE double strtod(const char *s,
	char **endPtr)
{
	return (double)__strtod (s, endPtr);
}
#else
extern double strtod(const char *s, char **endPtr);
#endif

#ifndef __STRICT_ANSI__
extern float __strtof(const char *, char **);
#if !defined(__LIBBUILD__)
static __INLINE float strtof(const char *s,
	char **endPtr)
{
	return __strtof (s, endPtr);
}
#else
extern float strtof(const char *s, char **endPtr);
#endif
#endif /* __STRICT_ANSI__ */

#endif  /* !defined(__mips_hard_float) */

#undef __FDLMATH_XDOUBLE

static __INLINE double atof(const char *s)
{
	return strtod(s, NULL);
}

/* --- Pseudo-random sequence generation --- */
int	rand	(void);
int	rand_r	(unsigned int *);
void	srand	(unsigned int);

/* --- Memory management --- */
void	free	(void *);
void	*malloc	(size_t);
void	*realloc (void *, size_t);
void 	*calloc	(size_t, size_t);

/* system hooks */
void	abort	(void) __attribute__ ((noreturn));
void	exit	(int) __attribute__ ((noreturn));
int	atexit	(void (*)(void));
int	system	(const char *);

/* enviroment hooks */
char	*getenv	(const char *);

  /* --- Searching and sorting --- */
void	*bsearch (const void *, const void *, 
		  size_t, size_t,
		  int (*)(const void *, const void *));

void	qsort	(void *base,
		 size_t, size_t , 
		 int (*)(const void *, const void *));

/* --- Integer arithmetic --- */
int	abs	(int);
div_t	div	(int, int);

long int labs	(long int);
ldiv_t	ldiv	(long int, long int);

#ifndef __STRICT_ANSI__
long long int llabs	(long long int);
lldiv_t	lldiv	(long long int, long long int);
#endif

/* --- Multibyte characters --- */
#if defined(__PIC32MX__)
#define MB_CUR_MAX	1
#else
extern int __mb_cur_max;
#define MB_CUR_MAX	__mb_cur_max 
#endif
int	mblen (const char *, size_t);
int	mbtowc (wchar_t *, const char *, size_t);
size_t	mbstowcs (wchar_t *, const char *, size_t);
int	wctomb (char *, wchar_t);
size_t	wcstombs (char *, const wchar_t *, size_t);

/* --- Macros --- */
#if defined(__OPTIMIZE__) && ! defined(__OPTIMIZE_SIZE__)
#define atoi(nptr)	((int) strtol((nptr), NULL, 10))
#define atol(nptr)	strtol((nptr), NULL, 10)
#define atof(nptr)	strtod((nptr), NULL)
#ifndef __STRICT_ANSI__
#define atoll(nptr)	strtoll((nptr), NULL, 10)
#endif
#endif

extern char *	itoa(char * buf, int val, int base);
extern char *	utoa(char * buf, unsigned val, int base);
extern char *	ltoa(char * buf, long val, int base);

#if !defined (_DEFINED_ULTOA)
extern char *	ultoa(char * buf, unsigned long val, int base);
#undef _STDLIB_ULTOA
#define _STDLIB_ULTOA
#ifdef __C32_VERSION__
#define _C32_ULTOA
#endif
#endif

#ifndef max
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)        (((a) < (b)) ? (a) : (b))
#endif

#ifdef __cplusplus
}
#endif
#endif /* !defined __STDLIB_H */
