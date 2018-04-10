##
## Makefile for Makefile in /home/walter_h/110borwein
## 
## Made by Hugo WALTER
## Login   <walter_h@epitech.net>
## 
## Started on  Mon Apr 10 14:33:29 2017 Hugo WALTER
## Last update Mon Apr 10 14:33:31 2017 Hugo WALTER
##

NAME	=	110borwein

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

INCS	=	-I./include

LIBS	=	-lm

CFLAGS	=	$(INCS) $(LIBS)

CC	=	gcc

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
