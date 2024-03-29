ROOT := $(shell pwd)
include $(ROOT)/../../defines.mk

PREFIX=xc32
TARGET=pic32mx
AR	=$(PREFIX)-ar
CC	=$(PREFIX)-gcc
STRIP   =$(PREFIX)-strip
OUTPUTFILE=processor.o

ISRFILE=default_isr_vectors.o

ISRFILE_PIC=default_isr_vectors_pic.o

STARTUP_OPTIONS = -D__LIBBUILD__
STARTUP_OPTIONS += -DINIT_SSX
STARTUP_OPTIONS += -DPIC32MM
STARTUP_OPTIONS += -DINIT_MCUASE
STARTUP_OPTIONS += -D__PIC32_HAS_MICROMIPS
STARTUP_OPTIONS += -mmicromips -D__mips_micromips
STARTUP_OPTIONS += -DINIT_INTCONVS
STARTUP_OPTIONS += -DINIT_DATA
STARTUP_OPTIONS += -DPIC32_SRS_SET_COUNT=2

STARTUPOBJ += crt0_micromips.o mcrt0_micromips.o crti_micromips.o crtn_micromips.o cpprt0_micromips.o crt0_micromips_pic.o cpprt0_micromips_pic.o

all: $(OUTPUTFILE) $(ISRFILE) $(ISRFILE_PIC) $(STARTUPOBJ)

install: $(OUTPUTFILE) $(ISRFILE) $(ISRFILE_PIC) $(STARTUPOBJ)

install-proc: $(OUTPUTFILE) $(ISRFILE) $(ISRFILE_PIC) $(STARTUPOBJ)

install-baseline:

install-src:

clean:
	rm -rf $(OUTPUTFILE) $(ISRFILE) $(ISRFILE_PIC) $(STARTUPOBJ)

$(OUTPUTFILE): p32MM0064GPL028.S
	$(CC) -c -o $@ $(SIZE_OPTION) $?

$(ISRFILE): p32MM0064GPL028_div.S
	$(CC) -c -o $@ $(SIZE_OPTION) $?

$(ISRFILE_PIC): p32MM0064GPL028_div.S
	$(CC) -fPIC -G0 -c -o $@ $(SIZE_OPTION) $?

mcrt0_micromips.o: ../../libpic32/startup/crt0.S
	$(CC) $(ASFLAGS) -D__32MM0064GPL028__ -c -DMCRT0 -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

crt0_micromips.o: ../../libpic32/startup/crt0.S
	$(CC) $(ASFLAGS) -D__32MM0064GPL028__ -c -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

cpprt0_micromips.o: ../../libpic32/startup/crt0.S
	$(CC) $(ASFLAGS) -D__32MM0064GPL028__ -c -DCPP_INIT -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

crti_micromips.o: ../../libpic32/startup/crti.s
	$(CC) $(ASFLAGS) -D__32MM0064GPL028__ -c -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

crtn_micromips.o: ../../libpic32/startup/crtn.s
	$(CC) $(ASFLAGS) -D__32MM0064GPL028__ -c -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

crt0_micromips_pic.o: ../../libpic32/startup/crt0_pic.S
	$(CC)  -fPIC -G0 $(ASFLAGS) -D__32MM0064GPL028__ -c -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

cpprt0_micromips_pic.o: ../../libpic32/startup/crt0_pic.S
	$(CC)  -fPIC -G0 $(ASFLAGS) -D__32MM0064GPL028__ -c -DCPP_INIT -mno-mips16 -mmicromips -I$(ROOT)/../../include $(STARTUP_OPTIONS) $< -o $@
	$(STRIP) $(STRIPFLAGS) $@

