CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -g
SDLCFLAGS = `sdl2-config --cflags`
SDLLFLAGS = `sdl2-config --libs` -lSDL2_ttf
INCLUDES = header.h 
SOURCES = main.c drawGrid.c grid.c getAltitudes.c
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = terrain

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(GCC) $(INCLUDES) $(OBJECTS) $(SDLLFLAGS) -lm -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) $(SDLCFLAGS) -c $<  -o $@ 

clean:
	rm -rf $(OBJECTS) $(OUTPUT)

re:
	make clean
	make all
