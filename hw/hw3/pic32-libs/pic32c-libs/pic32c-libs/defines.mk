PREFIX=pic32c
TARGET=pic32c
AR	=$(PREFIX)-ar
CC	=$(PREFIX)-gcc
STRIP   =$(PREFIX)-strip

SKIPARCHS=none

#EXCEPT	=-fexceptions

# Default to optimisation for size
OPTIM	=-O2 -fno-optimize-sibling-calls


# Minimal backtrace debug info, no assertion checking
DEBUG	= -g1
ASSERT	=-DNDEBUG=1
CFLAGS	=$(OPTIM) $(VAR) $(GPOPT) $(DEBUG) $(ASSERT) $(EXCEPT) -ffreestanding -ffunction-sections
ASFLAGS	=$(OPTIM) $(VAR) $(GPOPT) $(ASSERT) $(EXCEPT) -ffreestanding -ffunction-sections
STRIPFLAGS =-X

DESTROOT        =$(HOME)/xc32/build/install-image
TGTDESTDIR	=$(DESTROOT)/$(TARGET)
TGTLIBSRC	=$(DESTROOT)/pic32c-libs
LIBDESTDIR	=$(TGTDESTDIR)/lib
INCDESTDIR	=$(TGTDESTDIR)/include

# flags to pass to recursive makes
F		=ROOT=$(ROOT)
