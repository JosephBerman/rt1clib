CC = clang
CFLAGS = -Iinclude -Itest/Unity/src -Wall -Wextra -O2
UNITY_ROOT = test/Unity/src

SRC = $(wildcard src/*.c)
UNITY = $(wildcard $(UNITY_ROOT)/*.c)

SRC_OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
UNITY_OBJ = $(patsubst $(UNITY_ROOT)/%.c, build/unity_%.o, $(UNITY))
OBJ = $(SRC_OBJ) $(UNITY_OBJ)
DEVICE_OBJ = general

LIB = librt1clib.a


$(LIB): $(OBJ)
	ar rcs $@ $(OBJ)


build/unity_%.o: $(UNITY_ROOT)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(LIB) test/test_device_$(DEVICE_OBJ).c
	$(CC) $(CFLAGS) test/test_device_$(DEVICE_OBJ).c -L. -lrt1clib -o test/test.out

clean:
	rm -f build/*.o $(LIB) test/test

.PHONY: all clean test build
