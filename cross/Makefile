CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = headers.h
SOURCES = main.c print_char.c
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = cross

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(GCC) $(INCLUDES) $(OBJECTS) -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -rf $(OBJECTS) $(OUTPUT)

re:
	make clean
	make all
