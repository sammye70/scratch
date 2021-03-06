#
# Makefile for Borland's Borland-C++ compiler
#
CC=tcc
#
# Flags 
#     	-N  -- Check for stack overflow
#	-v  -- Enable debugging
#	-w  -- Turn on all warnings
#	-ml -- Large model
#
CFLAGS=-N -v -w -ml
OBJS= stat.obj ch_type.obj token.obj in_file.obj

all: stat.out stat.exe test.out

test.out: test.c stat.exe
	stat test.c >test.out

# This generates a test output based on another example
# in this book.
stat.out: stat.exe
	stat ..\calc3\calc3.c >stat.out

stat.exe: $(OBJS)
	$(CC) $(CFLAGS) -estat $(OBJS)

stat.obj: stat.c token.h
	$(CC) $(CFLAGS) -c stat.c

in_file.obj: in_file.c in_file.h
	$(CC) $(CFLAGS) -c in_file.c

ch_type.obj: ch_type.c ch_type.h
	$(CC) $(CFLAGS) -c ch_type.c

token.obj: token.c token.h ch_type.h
	$(CC) $(CFLAGS) -c token.c


clean:
	erase stat.exe 
	erase stat.obj
	erase ch_type.obj
	erase in_file.obj
	erase token.obj
