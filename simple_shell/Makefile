DIR := utils
CC :=gcc
INC := -Iinc
CFLAGS := -Wall -pedantic -Werror -Wextra
FILES := strings.c printer.c int_str.c swap.c print_env.c free_arraystring.c
FILESMAIN := main.c
SOURCES := $(foreach file,$(FILES),$(patsubst %,$(DIR)/%,$(file)))
OBJECTS := $(SOURCES:%.c=%.o)
EXE := simpleshell
UtilsLib := utils/utils.a
libshell := libshell/*.a

$(DIR)/%.o: $(DIR)/%.c
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)
all:  $(EXE)

$(EXE): $(FILESMAIN) $(UtilsLib) 
	$(CC) $(CFLAGS) $^ -o $@ $(libshell) $(UtilsLib) 

$(UtilsLib): $(OBJECTS)	
	ar -rc $(UtilsLib) $(OBJECTS)
clean:
	rm -f $(EXE) $(OBJECTS)
