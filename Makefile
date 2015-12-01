##
## Makefile for PhiloZob in /home/engueh_a/PhiloZob
##
## Made by Galilee Enguehard
## Login   <engueh_a@epitech.net>
##
## Started on  Wed Nov 25 11:04:13 2015 Galilee Enguehard
## Last update Tue Dec  1 12:46:14 2015 Galilee Enguehard
##

CC	= gcc

NAME	= PhiloZob

CFLAGS	+= -W -Wall -Werror -Wextra
CFLAGS	+= -Iinclude

LDFLAGS	= -lpthread

SRCS	= sources/main.c			\
	sources/create_threads.c		\
	sources/assign_thread.c			\
	sources/circular_linked_list.c		\
	sources/free_linked_list.c		\
	sources/start_routine.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f
PRINTF	= @printf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	$(PRINTF) '\033[1;32m> Compiled\033[0m\n'

clean:
	$(RM) $(OBJS)
	$(PRINTF) '\033[1;35m> Directory cleaned\033[0m\n'

fclean: clean
	$(RM) $(NAME)
	$(PRINTF) '\033[1;35m> Remove executable\033[0m\n'

re: fclean all

.PHONY: all clean fclean re
