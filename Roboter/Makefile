
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SRC = src/Roboter.c
OBJ = $(SRC:.c=.o)
TARGET = fir_tree

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all
