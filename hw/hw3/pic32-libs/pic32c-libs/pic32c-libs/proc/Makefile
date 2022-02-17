ROOT := $(shell pwd)
include $(ROOT)/../defines.mk

SUBDIRS=$(shell find . -mindepth 1 -type d  | grep -v .svn)

all: $(SUBDIRS)

install-proc: install

install-src:

install-baseline:

install: $(SUBDIRS)
	$(foreach dir,$(SUBDIRS), \
		rm -rf ${LIBDESTDIR}/proc/$(dir); \
		mkdir -p ${LIBDESTDIR}/proc/$(dir); \
		cp $(dir)/* ${LIBDESTDIR}/proc/$(dir) 2>>/dev/null; \
		)

clean: $(SUBDIRS)

$(SUBDIRS):

.PHONY: all install install-baseline install-proc clean $(SUBDIRS)
