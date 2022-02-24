##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME		=		libmy.a

SRC			=		my/format_modulo.c					\
					my/my_getnbr.c						\
					my/my_len.c							\
					my/my_printf.c						\
					my/my_putchar.c						\
					my/my_putnbr_base.c					\
					my/my_put_nbr.c						\
					my/my_putstr.c						\
					my/my_revstr.c						\
					my/my_strlen.c						\
					my/my_getnbr.c						\
					my/get_num.c						\
					my/my_compute_power_rec.c			\
					my/my_str_to_word_array.c			\
					my/mem_alloc_2d_array.c				\
					my/my_str_isnum.c					\
					my/my_strcmp.c						\
					my/int_char.c						\
					my/my_strcat.c						\
					my/my_str_isalpha.c					\
					my/my_strcpy.c

OBJ			=		$(SRC:.c=.o)

CC			=		gcc

all: 		$(NAME)

$(NAME): 	$(OBJ)
		ar rc -o $(NAME) $(SRC) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re