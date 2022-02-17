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
 * string.h : ANSI string function definitions
 */


#ifndef __STRING_H
#ifdef __cplusplus
extern "C" {
#endif
#define __STRING_H

#ifndef __C32_LEGACY_LIBC__
#define __C32_LEGACY_LIBC__
#endif

/* wrong gets offsetof !! 
*/
#include <stddef.h>

void	*memcpy	(void *, const void *, size_t);
void 	*memmove(void *,const void *, size_t);
char	*strcpy	(char *, const char *);
char	*strncpy (char *, const char *, size_t);
char	*strcat	(char *, const char *);
char	*strncat (char *, const char *, size_t);
int	memcmp	(const void *, const void *, size_t);
int	strcmp	(const char *, const char *);
int	strncmp	(const char *, const char *, size_t);
void	*memchr	(const void *, int, size_t);
char	*strchr	(const char *, int);
size_t	strcspn	(const char *, const char *);
char	*strpbrk (const char *, const char *);
char	*strrchr (const char *, int);
size_t	strspn	(const char *, const char *);
char	*strstr	(const char *, const char *);
char	*strtok	(char *, const char *);
char	*strtok_r (char *, const char *, char **);
void	*memset	(void *, int , size_t);
size_t	strlen	(const char *);

int	strcoll (const char *, const char *);
size_t	strxfrm (char *, const char *, size_t);

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
/* BSD backwards compatibility */
static __inline void bcopy (const void *s, void *d, size_t n) 
{ memcpy (d, s, n); }
static __inline int bcmp (const void *a, const void *b, size_t n) 
{ return memcmp (a, b, n); }
static __inline void bzero (void *d, size_t n) 
{ memset (d, 0, n); }
static __inline char * index (const char *s, int c) 
{ return strchr (s, c); }
static __inline char * rindex (const char *s, int c) 
{ return strrchr (s, c); }

/* BSD library functions */
int	 strcasecmp (const char *, const char *);
int	 strncasecmp (const char *, const char *, size_t);
int	 ffs (int);
int	 ffsl (long int);
#ifndef __STRICT_ANSI__
int	 ffsll (long long int);
#endif
#endif

/*
 * Putting this in here is really silly, but who am I to argue with X3J11?
 */
char *strerror	(int);
char *strerror_r (int, char *, size_t);

#ifdef __cplusplus
}
#endif
#endif /* !defined __STRING_H */
