CC= gcc
CFLAGS := -Wall -pedantic -Werror -Wextra
Utils := ./utils/*.c
UtilsOBJ := ./utils/*.o
FILES := main.c
EXE := simpleshell
UtilsLib := ./utils/utils.a
libshell :=./libshell/*.a
all: $(EXE)
	chmod +x $(EXE)
$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(libshell) $(UtilsLib) 
$(UtilsLib) : $(UtilsOBJ)	
	ar -rc $(UtilsLib) $(UtilsOBJ)
$(UtilsOBJ) : $(Utils)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f $(EXE)
