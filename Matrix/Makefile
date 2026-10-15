CC ?= gcc
CFLAGS ?= -Wall -Wextra -std=c99 -O2
LDFLAGS ?= -lm

SRCS = main.c utils.c gauss_operations.c matrix_operations.c vector_operations.c gauss_elimination.c matrix_transpose.c eigenvalues_vectors.c
OBJS = $(SRCS:.c=.o)
TARGET = matrix_calc

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) matrix.exe

