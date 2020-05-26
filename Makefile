##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## PING PONG LIB ! Page 1 : How play ping pong ?
##

SRC	=	pong.c

NAME	=	101pong

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -Llib/my -lmy -lm

clean:
	make -C lib/my clean

fclean:	clean
	make -C lib/my fclean

re:
	rm $(NAME)
	make -C lib/my fclean all
