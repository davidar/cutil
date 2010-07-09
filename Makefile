CC = gcc
AR = ar
CFLAGS = -std=gnu99 -Iinclude
OBJS = string.o io.o list.o hash.o

all: libcutil.a

clean:
	rm -f libcutil.a ${OBJS}

libcutil.a: ${OBJS}
	$(AR) rcs $@ $^

%.o: src/util/%.c
	$(CC) ${CFLAGS} -c $<
