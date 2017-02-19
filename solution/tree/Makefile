ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

#PROGS = main avltree que stack 
PROGS = run 

all:	$(PROGS)

$(PROGS):	$(LIBTOOL) main.o avltree.o
		$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS) $(LIBM)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libtool.inc
