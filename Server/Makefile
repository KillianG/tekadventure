##
## Makefile for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
## 
## Made by Marc PEREZ
## Login   <marc.perez@epitech.eu>
## 
## Started on  Fri Aug 25 13:40:52 2017 Marc PEREZ
## Last update Wed Sep 27 13:08:20 2017 Marc PEREZ
##

NAME		=	../serv

CC		=	gcc

CFLAGS		=	-pipe -march=native -fopenmp -Ofast -W -Wall -Wextra

CFLAGS_DEBUG	=	-pipe -march=native -Og -g3 -DDEBUG -W -Wall -Wextra

LDLIBS		=	-levent

CPPFLAGS	+=	-I ./inc

RM		=	rm -f

SRCS		=						\
		src/core/main.c					\
		src/core/socket.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 @$(CC) $(LDLIBS) -o $(NAME) $(OBJS)

debug:	CFLAGS=$(CFLAGS_DEBUG)
debug:	re

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
