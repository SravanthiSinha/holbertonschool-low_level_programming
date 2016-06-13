DIR := utils
CC :=gcc
INC := -Iinc
CFLAGS := -Wall -pedantic -Werror -Wextra
FILES := printf.c printintegers.c printnonintegers.c strings.c printnumber.c swap.c convert.c
FILESMAIN := main.c
SOURCES := $(foreach file,$(FILES),$(patsubst %,$(DIR)/%,$(file)))
OBJECTS := $(SOURCES:%.c=%.o)
UtilsLib := libprintf.a


$(DIR)/%.o: $(DIR)/%.c
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

all:  $(UtilsLib)

$(UtilsLib): $(OBJECTS)	
	ar -rc $(UtilsLib) $(OBJECTS)
clean:
	rm -f $(UtilsLIb) $(OBJECTS)
