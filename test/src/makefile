CC = gcc
SRC = main.c funs.c initial.c
OBJ = $(SRC: .c= .o)
NAME = prog
RM = rm -f
CFLAGS = $(sdl2-config --cflags --libs)

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
clean:
	$(RM) *~ $(NAME)
oclean:
	$(RM) $(OBJ)
fclean: clean oclean

re: oclean all

/* gcc *.c -o prog $(sdl2-config --cflags --libs) */
