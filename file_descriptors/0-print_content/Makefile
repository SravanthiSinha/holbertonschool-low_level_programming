CC= gcc
CFLAGS := -Wall -pedantic -Werror -Wextra
FILES := main.c
EXE := 0-print_content
all: $(EXE)

$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f $(EXE)
