##
## Makefile for  in /home/loic/dev/epitech/c/philosophes
##
## Made by loic lefloch
## Login   <lefloc_l@epitech.net>
##
## Started on  Sun Mar 23 15:07:41 2014 loic lefloch
## Last update  dim. mars 23 19:50:31 2014 lefloc_l
##

CC=	gcc
RM=	rm -f

NAME=	philo

SRC=	philo.c \
	window.c \
	Utils.c \
	checker.c \
	calcul.c \
	text.c \

ECHO=	echo

LDFLAGS=	-Wall -Wextra -lSDL -lSDL_image -lSDL_ttf -pthread

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@$(ECHO) "\033[0;32m> Philosophe compiled\033[0m"
	@$(ECHO) "\033[1;36m> On ne dit pas que c'est moche. C'est juste graphiquement mal optimisé.\033[0m"

clean:
	$(RM) $(OBJ)
	@$(ECHO) "\033[0;31m> Directory cleaned\033[0m"
	@cat ./homer.txt
	@$(ECHO) "\033[0;35m> We love asteks <3\033[0m"

fclean:	clean
	$(RM) $(NAME)
	@$(ECHO) "\033[0;31m> Executable cleaned\033[0m"
	@$(ECHO) "\033[0;35m> We love asteks <3\033[0m"

joke:
	@$(ECHO) "\033[1;31m>Un jour un programme dit à son env Et ! PATH le chemin !< \033[0m"

lol:
	@$(ECHO) "\033[1;31m>LOL< \033[0m"

re:	fclean all

.PHONY:	all clean fclean re
