TARGET = restaurante

CC = cc

CFLAGS = -Wall -Wextra -std=c99

SCRS = $(wildcard *.c) $(wildcard src/*.c)

all:
	$(CC) $(CFLAGS) $(SCRS) -o $(TARGET)

clean:
	rm -f $(TARGET)