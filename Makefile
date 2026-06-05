TARGET = restaurante
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Detecta o Sistema Operacional
ifeq ($(OS),Windows_NT)
    # Configurações para Windows
    RM = del /Q /F
    EXE = .exe
else
    # Configurações para Linux/macOS
    RM = rm -f
    EXE = 
endif

SRCS = $(wildcard *.c) $(wildcard src/*.c)

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)$(EXE)

clean:
	$(RM) $(TARGET)$(EXE)
