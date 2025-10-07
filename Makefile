TARGET = genpass

CC = gcc
CFLAGS = -Wall -Wextra -Iincludes

SRC = src/main.c src/genpass.c src/strings.c src/copyclip.c
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)


