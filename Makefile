NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils_bonus.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus : $(NAME)

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all bonus fclean clean re