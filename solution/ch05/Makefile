ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

PROGS = run
O_FILES = main.o hashquad.o

all:	$(PROGS)

$(PROGS):	$(O_FILES)
		$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS) $(LIBM)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libtool.inc
