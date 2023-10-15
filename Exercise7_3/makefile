SRCS = $(wildcard Exercise7_?.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CFLAGS += -Wall -g
LIBS = -lm

all: $(PROGS)

%: %.c stack.c
	$(CC) $(CFLAGS) -o $@ $< stack.c $(LIBS)

clean:
	rm -f *~
	rm -f $(PROGS)