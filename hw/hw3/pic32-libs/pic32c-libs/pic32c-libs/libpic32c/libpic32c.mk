include	$(ROOT)/../defines.mk

include $(ROOT)/stubs/Makefile.inc
include $(ROOT)/startup/Makefile.inc

vpath	%.c		$(_VPATH)
vpath	%.cc		$(_VPATH)
vpath	%.s		$(_VPATH)
vpath	%.sx		$(_VPATH)
vpath	%.S		$(_VPATH)
vpath	%.h		$(_VPATH)
vpath	Makefile	$(_VPATH)

# Force optimisation, but no inlining/unrolling
OPTIM	=-O2 -fno-inline-functions -fno-unroll-loops \
	 -foptimize-sibling-calls -ffunction-sections \
	 -fno-common -fno-builtin-exit -fno-builtin-abort \
	 -fno-jump-tables

CPPFLAGS += $(GPOPT) -DNDEBUG=1 -I$(ROOT)/include -I$(ROOT)/../include
CFLAGS += $(OPTIM) $(VAR) $(GPOPT) -DNDEBUG=1 -D__LIBBUILD__ -I$(ROOT)/include -I$(ROOT)/../include -g1 -Wcast-align -Wall -mchp-stack-usage #-mno-smart-io
ASFLAGS += $(VAR) -DNDEBUG=1 -D__LIBBUILD__

all: libpic32c.a #startup_modules

libpic32c.a: $(LIBOBJ)
	$(STRIP) $(STRIPFLAGS) $(LIBOBJ)
	$(AR) rcs $@ $(LIBOBJ)

#startup_modules:  Makefile $(SUPOBJ)

install: libpic32c.a #startup_modules
	mkdir -p $(LIBDESTDIR)/$(SUBDIR)
	rm -f $(LIBDESTDIR)/$(SUBDIR)/libpic32c.a
	cp -p libpic32c.a $(LIBDESTDIR)/$(SUBDIR)/libpic32c.a
	#@rm -f $(addprefix $(LIBDESTDIR)/$(SUBDIR)/,$(SUPOBJ))
	#cp -p $(SUPOBJ) $(LIBDESTDIR)/$(SUBDIR)

clean:
	rm -f libpic32c.a *.o core* *~

