_VPATH	+=:$(ROOT)/stubs

LIBOBJ	+= _exit.o
LIBOBJ	+= close.o _close.o
LIBOBJ	+= data_init.o
LIBOBJ	+= tcm_stack_init.o
LIBOBJ	+= fstat.o _fstat.o
LIBOBJ	+= getpid.o _getpid.o
LIBOBJ	+= isatty.o _isatty.o
LIBOBJ	+= kill.o _kill.o
LIBOBJ	+= link.o _link.o
LIBOBJ	+= lseek.o _lseek.o
LIBOBJ	+= read.o _read.o
LIBOBJ	+= sbrk.o 
LIBOBJ	+= unlink.o _unlink.o
LIBOBJ	+= write.o _write.o
LIBOBJ  += open.o _open.o
LIBOBJ	+= _mon_getc.o
LIBOBJ	+= _mon_putc.o
LIBOBJ	+= _mon_puts.o
LIBOBJ	+= _mon_write.o

sbrk.o: sbrk.c
	$(CC) $(CFLAGS) -c -DPAGESIZE=128 $< -o $@
