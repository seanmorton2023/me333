#
# Global makefile for libraries
#
include defines.mk
SHELL=/bin/bash

SUBDIRS	= rcfastm dsp libpic32 lega-c math proc ieee debugsupport peripheral sol cppcfl dspr2

# We ship with source code for some libraries
SRCINSTALL_SUBDIRS = peripheral debugsupport

all: create-machine $(SUBDIRS)

install: $(SUBDIRS) install-headers

install-src: $(SUBDIRS)
	cp Makefile $(TGTLIBSRC)
	cp defines.mk $(TGTLIBSRC)
	cp HOWTO-build-libraries-from-windows.txt $(TGTLIBSRC)
	$(foreach dir,$(shell find include -type d  | grep -v .svn), \
		mkdir -p $(TGTLIBSRC)/$(dir); \
		cp $(dir)/* ${TGTLIBSRC}/$(dir) 2>>/dev/null; )
	cd $(TGTLIBSRC)/include && rm -rf machine && cp -RL mips machine && cd -

install-baseline: $(SUBDIRS) install-headers

install-proc: proc

clean: $(SUBDIRS)

create-machine:
	cd include && rm -rf machine && cp -RL mips machine && cd ..
	cd include/lega-c && rm -rf machine && rm -rf mips && cd .. && \
		cp -RL mips ./lega-c/mips && cp -RL mips ./lega-c/machine && cd ..
	cd include && cp ./sys/appio.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/asm.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/attribs.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/cdefs.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/endian.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/kmem.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/l1cache.h ./lega-c/sys/ && cd ..
	cd include && cp ./sys/swap.h ./lega-c/sys/ && cd ..

# Each subdirectory is optional, so only build the ones that are present
$(SUBDIRS):
	@if [[ -d $@ ]] ; then $(MAKE) -C $@ $(MAKECMDGOALS) ; fi

install-headers: create-machine
	$(foreach dir,$(shell find include -type d | grep -v .svn), \
		mkdir -p $(TGTDESTDIR)/$(dir); 2>>/dev/null; )
	find include -type f ! -name "xc.h" -exec cp {} ${TGTDESTDIR}/{} \; 
	cd $(INCDESTDIR) && rm -rf machine && cp -RL mips machine && cd -
	cd $(INCDESTDIR)/lega-c && rm -rf machine && rm -rf mips && cd .. && \
		cp -RL mips ./lega-c/mips && cp -RL mips ./lega-c/machine && cd -
	cd $(INCDESTDIR) && cp ./sys/appio.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/asm.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/attribs.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/cdefs.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/endian.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/kmem.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/l1cache.h ./lega-c/sys/ && cd -
	cd $(INCDESTDIR) && cp ./sys/swap.h ./lega-c/sys/ && cd -
	mkdir -p $(TGTDESTDIR)/pic32mx/lib/proc/32MXGENERIC && cp ./proc/32MXGENERIC/procdefs.ld $(TGTDESTDIR)/pic32mx/lib/proc/32MXGENERIC/
	mkdir -p $(TGTDESTDIR)/lib/proc/32MXGENERIC && cp ./proc/32MXGENERIC/procdefs.ld $(TGTDESTDIR)/lib/proc/32MXGENERIC/

.PHONY: all install clean install-headers install-baseline install-proc
.PHONY: $(SUBDIRS)

