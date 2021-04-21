##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC	=	./src/main.c			\
		./src/get_file_info.c	\
		./src/quests.c			\
		./src/setup.c			\
		./src/parse_quests_info.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	quest

CFLAGS 	=	-Wshadow \
			-Wall \
			-Wextra \
			-W \
			-I includes \
			-I ./lib/my

LDFLAGS = 	-Llib/my \
			-lmy

all:	$(NAME)

$(NAME):	$(OBJ) ./lib/my/libmy.a
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

./lib/my/libmy.a:
	make -C ./lib/my

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)
	rm -f ./lib/libmy.a
	rm -f $(OBJ)
	rm -f crypt

re:	fclean	all