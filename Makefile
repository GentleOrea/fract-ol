#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 11:17:30 by ygarrot           #+#    #+#              #
#    Updated: 2018/03/16 11:07:31 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

SRC_FOLDER = src/

SRC_FP = draw_base.c \
		init.c \
		shortcut.c \
		mlx_rgb.c \
		main.c \

#Colors
_RED=\x1b[31m
_GREEN=\x1b[32m
_BLUE=\x1b[94m
_WHITE=\x1b[37m
_END=\x1b[0m

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FP))

INCLUDE =  includes/

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INCLUDE)
	@printf "                                                        \r"
	@printf " $(_BLUE)Compiling $@$(_END)\r"

$(NAME): $(OBJ)
	@printf "                                                        \r"
	make -C libft -j
	@gcc $(FLAGS) -o $(NAME) $^ -L libft -l ft -lmlx -framework OpenGl -framework AppKit
	@printf "                                                        \r"
	@printf "fractol built\n"

test: all clean

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	
fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
