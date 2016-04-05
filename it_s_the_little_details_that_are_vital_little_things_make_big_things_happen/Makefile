# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=gcc
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-Wall -pedantic -Werror -Wextra -c

all:	libholbertonschool.a clean

clean:
	rm -rf *o 

libholbertonschool.a:./*.o
	ar -rc libholbertonschool.a ./*.o
./*.o:./src/*.c ./inc/*.h
	$(CC) $(CFLAGS) ./inc/*.h ./src/*.c

