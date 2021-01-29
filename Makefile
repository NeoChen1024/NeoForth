CC	= cc
OPT	= -Ofast -finline -flto -DEXPECT_MACRO
CFLAGS	= $(OPT) -pipe -fPIC -fPIE -I. -g -std=c11 -pedantic -D_POSIX_C_SOURCE=2008 -Wall -Wextra -Wno-unused-parameter
OBJS	= neoforth.o

.PHONY: all clean countline test

all: neoforth

neoforth: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o neoforth

countline:
	wc -l *.h *.c

clean:
	rm -f $(OBJS) neoforth
