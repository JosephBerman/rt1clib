CC = clang
CFLAGS = -I.


DEPS = device_common.h
OBJ = device_common.o




%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
