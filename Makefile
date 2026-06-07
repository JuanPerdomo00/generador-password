TARGET = genpass
VERSION = 1.0.1

CC = gcc
CFLAGS = -Wall -Wextra -Iincludes -O2 -DVERSION=\"$(VERSION)\"

SRC = src/main.c src/genpass.c src/strings.c src/copyclip.c src/random.c
OBJ = $(SRC:.c=.o)

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	install -D -m 755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Installed $(TARGET) to $(DESTDIR)$(BINDIR)/$(TARGET)"

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	@echo "Uninstalled $(TARGET)"

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: install uninstall clean


