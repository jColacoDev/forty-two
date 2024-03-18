CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./src
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)
INCDIR = $(SRCDIR)
INCS = $(wildcard $(INCDIR)/*.h)
TARGET = bsq

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
