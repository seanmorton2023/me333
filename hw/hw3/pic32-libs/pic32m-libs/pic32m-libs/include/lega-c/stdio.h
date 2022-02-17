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
 * stdio.h : standard I/O library definitions
 */


#ifndef __STDIO_H
#ifdef __cplusplus
extern "C"
  {
#endif
#define __STDIO_H

#ifndef __C32_LEGACY_LIBC__
#define __C32_LEGACY_LIBC__
#endif

    /* _POSIX_SOURCE features in here */
#include <sys/posix.h>

    /* get va_list definition */
#define __need_va_list
#include <stdarg.h>

    /* --- Inclusions --- */
#include <stddef.h>  /* bogus gets offsetof */

#if !defined(_ANSI_SOURCE) || defined(_POSIX_SOURCE)
#include <sys/types.h>
#endif

    /* --- Constants --- */
#define EOF  (-1)
#define BUFSIZ  64
#if defined(__XC32)
#define __STDOUT_BUFSIZ 0
#else
#define __STDOUT_BUFSIZ 32
#endif

#define _IOFBF  0
#define _IOLBF  _IO_LBUF
#define _IONBF  (-1)

#define L_tmpnam 20  /* "/tmp/Tmp00000.00000\0" */
#define TMP_MAX  99999   /* max calls to tmpnam() */

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define FILENAME_MAX 1024

#define FOPEN_MAX 16  /* min number of open files */

#include <libc_thread.h>

#if !defined(_ANSI_SOURCE) || defined(_POSIX_SOURCE)
    typedef off_t   fpos_t;
#else
    __extension__ typedef long long fpos_t;
#endif

    struct _iobfuncs;

    typedef struct _iob
      {
        int   _io_count;
        union _iou
          {
            unsigned char *_io_ptr;
            int  _io_char;
          } _io;
        unsigned char  *_io_buf;
        int   _io_bufsiz;
        unsigned short _io_flags;
        short   _io_fd;
        void   *_io_lock;
        const struct _iobfuncs *_io_funcs;
      } FILE;

    /* --- Flag bits --- */
#define _IO_READ 0x0001
#define _IO_WRITE 0x0002
#define _IO_UPDATE 0x0004
#define _IO_LBUF 0x0008
#define _IO_MYBUF 0x0010
#define _IO_EOF  0x0020
#define _IO_ERR  0x0040
#define _IO_STRING 0x0080
    /*#define _IO_TEMP 0x0100*/
#define _IO_STRALLOC 0x0200
#define _IO_TTY  0x1000
#define _IO_BINARY 0x8000

#define _io_testflag(f, flag) ((f)->_io_flags & (flag))
#define _io_setflag(f, flag) ((f)->_io_flags |= (flag))
#define _io_clearflag(f, flag) ((f)->_io_flags &= ~(flag))

    /* --- Prototypes --- */

    /* --- Streams: open and close --- */
    int fclose (FILE *);
    FILE *fopen (const char *, const char *);
    FILE *freopen (const char *, const char *, FILE *);
    FILE *tmpfile (void);

    /* --- Streams: input --- */
    int fgetc (FILE *);
    char *fgets (char *, int , FILE *);
    size_t fread (void *, size_t, size_t, FILE *);
    int fscanf (FILE *, const char *, ...);
    int getc (FILE *);
    int getchar (void);
    char *gets (char *);
    int scanf (const char *, ...);
    int sscanf (const char *, const char *, ...);
    int ungetc (int, FILE *);

    /* --- Streams: output --- */
    int fprintf (FILE *, const char *, ...);
    int fputc (int , FILE *);
    int fputs (const char *, FILE *);
    size_t fwrite (const void *, size_t, size_t, FILE *);
    int printf (const char *, ...);
    int putc (int, FILE *);
    int putchar (int);
    int puts (const char *);
    int sprintf (char *, const char *, ...);

    int vfprintf (FILE *, const char *, va_list);
    int vprintf (const char *, va_list);
    int vsprintf (char *, const char *, va_list);

    int vscanf (const char *, va_list);
    int vsscanf (const char *, const char *, va_list);
    int vfscanf (FILE *, const char *, va_list);

#if !defined(_POSIX_SOURCE) && !defined(_ANSI_SOURCE)
    int snprintf (char *, size_t, const char *, ...);
    int vsnprintf (char *, size_t, const char *, va_list);
    int asprintf (char **, const char *, ...);
    int vasprintf (char **, const char *, va_list);
#endif
      
///\ lghica
#if defined(__C32_VERSION__) && !defined(__STRICT_ANSI__)
#define define_smartio_variants(rettype,funcname,...) \
extern rettype _ ## funcname ## _cdeEfFgGnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEfFgGnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEfFnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEfFnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEgGnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEgGnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdeEnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdfFgGnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdfFgGnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdfFnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdfFnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdgGnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdgGnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdnopsuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _cdnopuxX (__VA_ARGS__); \
extern rettype _ ## funcname ## _eE (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEfF (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEfFgG (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEfFgGs (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEfFs (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEgG (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEgGs (__VA_ARGS__); \
extern rettype _ ## funcname ## _eEs (__VA_ARGS__); \
extern rettype _ ## funcname ## _fF (__VA_ARGS__); \
extern rettype _ ## funcname ## _fFgG (__VA_ARGS__); \
extern rettype _ ## funcname ## _fFgGs (__VA_ARGS__); \
extern rettype _ ## funcname ## _fFs (__VA_ARGS__); \
extern rettype _ ## funcname ## _gG (__VA_ARGS__); \
extern rettype _ ## funcname ## _gGs (__VA_ARGS__); \
extern rettype _ ## funcname ## _s (__VA_ARGS__); \
extern rettype _ ## funcname (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEfFgGnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEfFgGnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEfFnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEfFnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEgGnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEgGnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdeEnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdfFgGnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdfFgGnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdfFnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdfFnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdgGnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdgGnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdnopsuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _cdnopuxX (__VA_ARGS__); \
extern rettype _d ## funcname ## _eE (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEfF (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEfFgG (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEfFgGs (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEfFs (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEgG (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEgGs (__VA_ARGS__); \
extern rettype _d ## funcname ## _eEs (__VA_ARGS__); \
extern rettype _d ## funcname ## _fF (__VA_ARGS__); \
extern rettype _d ## funcname ## _fFgG (__VA_ARGS__); \
extern rettype _d ## funcname ## _fFgGs (__VA_ARGS__); \
extern rettype _d ## funcname ## _fFs (__VA_ARGS__); \
extern rettype _d ## funcname ## _gG (__VA_ARGS__); \
extern rettype _d ## funcname ## _gGs (__VA_ARGS__); \
extern rettype _d ## funcname ## _s (__VA_ARGS__); \
extern rettype _d ## funcname (__VA_ARGS__);
#else
#define define_smartio_variants(rettype,funcname,...)
#endif /* !STRICT_ANSI && C32_VERSION */

      
            
      
#if !defined(__STRICT_ANSI__) && defined(__PIC32MX__) && !defined(__LIBBUILD__)

#if 0

#define printf(fmt,a...) __builtin_printf(fmt,##a)
#define fprintf(file,fmt,a...) __builtin_fprintf(file,fmt,##a)
#define vfprintf(file,fmt,arglist) __builtin_vfprintf(file,fmt,arglist)
#define sprintf(stream,fmt,a...) __builtin_sprintf(stream,fmt,##a)
#define vprintf(fmt,arglist) __builtin_vprintf(fmt,arglist)
#define vsprintf(stream,fmt,arglist) __builtin_vsprintf(stream,fmt,arglist)
#define scanf(fmt,a...) __builtin_scanf(fmt,##a)
#define fscanf(fileval,fmt,a...) __builtin_fscanf(fileval,fmt,##a)
#define sscanf(instring,fmt,a...) __builtin_sscanf(instring,fmt,##a)
#define vfscanf(fileval,fmt,arglist) __builtin_vfscanf(fileval,fmt,arglist)
#define vsscanf(instring,fmt,arglist) __builtin_vsscanf(instring,fmt,arglist)
#define vscanf(fmt,arglist) __builtin_vscanf(fmt,arglist)

#if !defined(_POSIX_SOURCE) && !defined(_ANSI_SOURCE)
#define snprintf(stream,sizeval,fmt,a...) __builtin_snprintf(stream,sizeval,fmt,##a)
#define vsnprintf(stream,sizeval,fmt,arglist) __builtin_vsnprintf(stream,sizeval,fmt,arglist)
#define vasprintf(stream,fmt,arglist) __builtin_vasprintf(stream,fmt,arglist)
#define asprintf(stream,fmt,a...) __builtin_asprintf(stream,fmt,##a)
#endif
      
      
#endif///\ if 0

#if !defined(PIC32_STARTER_KIT) && !defined(__APPIO_DEBUG) && !defined(_APPIO_DEBUG)
extern int _mon_getc (int canblock);
extern void _mon_putc (char c);
extern void _mon_puts (const char * s);
extern void _mon_write (const char * s, unsigned int count);
#endif

#endif

    /* --- Streams: inquiry and control --- */
    void clearerr (FILE *);
    int feof (FILE *);
    int ferror (FILE *);
    int fflush (FILE *);
    int fgetpos (FILE *, fpos_t *);
    int fseek (FILE *, long int, int);
    int fsetpos (FILE *, const fpos_t *);
    long int ftell (FILE *);
    void rewind (FILE *);
    void setbuf (FILE *, char *);
    int setvbuf (FILE *, char *, int, size_t);

    /* --- File system manipulation --- */
    int remove (const char *);
    int rename (const char *, const char *);

    /* --- Miscellaneous --- */
    char *tmpnam (char *s);
    void perror (const char *s);
#ifndef _POSIX_SOURCE
    extern int sys_nerr;
    extern const char * const sys_errlist[];
#endif

#ifndef _ANSI_SOURCE
#define L_cuserid (32+1)  /* Arbitrary hmm */
#define STREAM_MAX INT_MAX
#endif

    /* internal for use by macros */
    extern int _fwalk (int (*) (FILE *));

    /* --- Streams: input --- */
#define getc(f)  fgetc(f)
#define getchar() getc(stdin)
#define putc(c, f) fputc(c, f)
#define putchar(c) putc(c, stdout)

    /* --- Streams: inquiry and control --- */
#define feof(f)  (_io_testflag((f), _IO_EOF) != 0)
#define ferror(f) (_io_testflag((f), _IO_ERR) != 0)

    void clearerr(FILE *);

#ifdef __cplusplus
  }
#endif
#endif /* !defined __STDIO_H */

