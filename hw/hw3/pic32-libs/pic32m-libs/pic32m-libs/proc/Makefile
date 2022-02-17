ROOT := $(shell pwd)
include $(ROOT)/../defines.mk

# this is now built in two phases: first the generic device, then all devices
# once part-support is available.
ifeq ($(PIC32M_GENERIC_ONLY),)
PROC_SUBDIRS = $(shell find . -mindepth 1 -type d  | grep -v .svn)
else
PROC_SUBDIRS = 32MXGENERIC
endif

all: $(PROC_SUBDIRS)

install-proc: install

install-src:

install-baseline:

install: $(PROC_SUBDIRS)
	for dir in $(PROC_SUBDIRS); do \
	  rm -rf ${LIBDESTDIR}/proc/$${dir}; \
	  mkdir -p ${LIBDESTDIR}/proc/$${dir}; \
	  cp $${dir}/* ${LIBDESTDIR}/proc/$${dir} 2>>/dev/null; \
	  rm ${LIBDESTDIR}/proc/$${dir}/Makefile; \
	done

clean: $(PROC_SUBDIRS)

$(PROC_SUBDIRS):
	@$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: all install install-baseline install-proc clean $(PROC_SUBDIRS)
