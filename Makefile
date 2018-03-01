##
## Makefile for Makefile in /home/bechad_p/rendu/PSU_2014_minishell2
## 
## Made by Pierre Bechade
## Login   <bechad_p@epitech.net>
## 
## Started on  Thu Nov 27 16:48:32 2014 Pierre Bechade
## Last update Sun Nov 30 15:33:23 2014 Pierre Bechade
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Werror -Wextra -g3

CFLAGS	+=	-I./include/

NAME	=	mysh

SRCS	=	src/my_sh.c			\
		src/tools.c			\
		src/tools2.c			\
		src/tools3.c			\
		src/exe_path.c			\
		src/builtin.c			\
		src/my_sighandler.c		\
		src/my_env.c			\
		src/my_unsetenv.c		\
		src/my_setenv.c			\
		src/my_exit.c			\
		src/error_functions.c		\
		src/my_cd.c			\
		src/my_cd_tools.c		\
		src/my_cd_tools2.c		\
		src/my_parse.c			\
		src/my_tools_parse.c		\
		src/tree.c			\
		src/my_calcul.c			\
		src/my_echo_env.c

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS) 
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(HH) $(LIB) 

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
re	:	fclean all
