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
 * time.h : ANSII/POSIX time fdefinitions
 */


#ifndef __TIME_H
#ifdef __cplusplus
extern "C" {
#endif
#define __TIME_H

#ifndef __C32_LEGACY_LIBC__
#define __C32_LEGACY_LIBC__
#endif

/* This is ANSI C and POSIX compliant
 */

/* --- Inclusions --- */
#include <machine/ansi.h>
#include <stddef.h>

/* --- Types --- */

#ifdef _CLOCK_T_
typedef _CLOCK_T_ clock_t;
#undef _CLOCK_T_
#endif

#ifdef _TIME_T_
typedef _TIME_T_ time_t;
#undef _TIME_T_
#endif

/* --- Structures --- */
struct tm {
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
	/* BSD fields */
	long	tm_gmtoff;
	char	*tm_zone;
};

/* --- Prototypes --- */
time_t	time(time_t *);
clock_t	clock(void);
char	*asctime_r(const struct tm *, char *);
char	*asctime(const struct tm *);
char	*ctime_r(const time_t *, char *);
char	*ctime(const time_t *);
double	difftime(time_t, time_t);
struct tm *gmtime_r(const time_t *, struct tm *);
struct tm *gmtime(const time_t *);
struct tm *localtime_r(const time_t *, struct tm *);
struct tm *localtime(const time_t *);
time_t	mktime(struct tm *);
size_t	strftime(char *, size_t, 
		 const char *, const struct tm *);

/* CLOCKS_PER_SEC very sys dependent 
*/
#include <sys/clock.h>

#if !defined(_ANSI_SOURCE)
void	tzset(void);
extern  char 	*tzname[2];
#endif

#ifdef __cplusplus
}
#endif
#endif /* !defined __TIME_H */
