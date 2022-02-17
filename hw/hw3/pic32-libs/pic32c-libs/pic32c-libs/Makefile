#
# Global makefile for libraries
#
include defines.mk
SHELL=/bin/bash

SUBDIRS	= libpic32c proc

# We ship with source code for some libraries
SRCINSTALL_SUBDIRS = libpic32c proc

all: $(SUBDIRS)

install: $(SUBDIRS) install-headers install-proc

install-src: $(SUBDIRS)
	cp Makefile $(TGTLIBSRC)
	cp defines.mk $(TGTLIBSRC)
	$(foreach dir,$(shell find include -type d  | grep -v .svn), \
		mkdir -p $(TGTLIBSRC)/$(dir); \
		cp $(dir)/* ${TGTLIBSRC}/$(dir) 2>>/dev/null; )
	cd $(TGTLIBSRC)/include && cd -

install-baseline: $(SUBDIRS) install-headers

install-proc: proc

clean: $(SUBDIRS)

# Each subdirectory is optional, so only build the ones that are present
$(SUBDIRS):
	@if [[ -d $@ ]] ; then $(MAKE) -C $@ $(MAKECMDGOALS) ; fi

install-headers:
	$(foreach dir,$(shell find include -type d  | grep -v .svn), \
		mkdir -p $(TGTDESTDIR)/$(dir);  2>>/dev/null; )
	find include -type f ! -name "xc.h" -exec cp {} ${TGTDESTDIR}/{} \; 
	$(foreach dir,$(shell find include_mcc -type d  | grep -v .svn), \
		mkdir -p $(TGTDESTDIR)/$(dir);  2>>/dev/null; )
	@if [[ -d include_mcc ]] ; then find include_mcc -type f ! -name "xc.h" -exec cp {} ${TGTDESTDIR}/{} \; ; fi

install-headers-proc:
	$(foreach dir,$(shell find include/proc -type d  | grep -v .svn), \
		mkdir -p $(TGTDESTDIR)/$(dir); \
		cp $(dir)/* ${TGTDESTDIR}/$(dir) 2>>/dev/null; )
	$(foreach dir,$(shell find include_mcc/proc -type d  | grep -v .svn), \
		mkdir -p $(TGTDESTDIR)/$(dir); \
		cp $(dir)/* ${TGTDESTDIR}/$(dir) 2>>/dev/null; )

.PHONY: all install clean install-headers install-headers-proc install-baseline install-proc
.PHONY: $(SUBDIRS)

