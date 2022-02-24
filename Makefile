##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	sources/help.c							\
			sources/minishell.c						\
			sources/sub_functions.c					\
			sources/child.c							\
			sources/unix_functions/cd.c				\
			sources/unix_functions/env.c			\
			sources/unix_functions/unsetenv.c		\
			sources/unix_functions/setenv.c			\
			sources/unix_functions/exit.c

SRC_MAIN	=	main.c

SRC_TESTS	=	tests/tests_project.c				\
				tests/tests_exit.c					\
				tests/tests_env.c					\

OBJ		=	$(SRC_MAIN:.c=.o)					\
			$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -I./includes -g

TEST_FLAGS	=	--coverage -lcriterion

LIB		=	-L./lib -lmy

NAME		=	mysh

NAME_TEST	=	unit_tests

all:		libr $(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:		libr
			$(CC) -o $(NAME_TEST) $(SRC_TESTS) $(SRC) $(LIB) $(TEST_FLAGS) \
			$(CFLAGS)
			./$(NAME_TEST)
			gcovr --exclude lib --exclude tests

clean:
			$(RM) $(OBJ)
			$(RM) *.gc*
			$(RM) *~
			$(MAKE) -C lib/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAME_TEST)
			$(MAKE) -C lib/ fclean

libr:
			$(MAKE) -C lib/

re:		fclean all

.PHONY: clean libr
