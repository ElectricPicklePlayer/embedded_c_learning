CC      = gcc
CFLAGS  = -Wall -Wextra -Wdangling-pointer -g -fsanitize=address
TARGET  = ./build/scope
SRCS    = main.c counter.c
OBJS    = $(patsubst %.c,./build/%.o,$(SRCS))

.PHONY: all clean

all: ./build $(TARGET)

./build:
	mkdir -p ./build

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

./build/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ./build
