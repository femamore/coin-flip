CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c2x -pedantic
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
BIN = main

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : clean
clean:
	$(RM) $(OBJS) $(BIN)