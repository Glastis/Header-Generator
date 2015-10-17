##
## Makefile for hmake
## 
## Made by glastis
## 
## Last update Sat Oct 17 19:26:54 2015 glastis
##

SRC=			./src/add_function.c \
			./src/get_c_files.c \
			./src/get_dir.c \
			./src/is_func.c \
			./src/is_same.c \
			./src/main.c \
			./src/str_coupler.c

OBJ=			 $(SRC:.c=.o)

NAME=			 hmake

CFLAGS=			-Wall -Wextra -Werror -ansi -pedantic

all:			$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
