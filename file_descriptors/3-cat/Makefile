CC= gcc
CFLAGS := -Wall -pedantic -Werror -Wextra
FILES := main.c print_char.c
EXE := 3-cat
all: $(EXE)

$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f $(EXE)
