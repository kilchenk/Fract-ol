# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 22:26:39 by kilchenk          #+#    #+#              #
#    Updated: 2023/08/24 15:51:36 by kilchenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -O3

SRCS	:= src/main.c src/utils.c src/input.c src/mandelbrot.c src/colors.c \
		src/keys.c src/julia.c src/burningship.c

OBJS	:= $(SRCS:.c=.o)

%.o: %.c
	@ $(CC) -c $(CFLAGS) $< -o ${<:.c=.o}
	@echo "\033[92m•\033[0m\c"

RM		    := rm -f

$(NAME): $(OBJS)
	@ $(MAKE) -C mlx all >/dev/null 2>&1
	@ cp ./mlx/libmlx.a .
	@ $(MAKE) -C libft all >/dev/null 2>&1
	@ cp ./libft/libft.a .
	@ $(CC) $(CFLAGS) -Ofast -o $(NAME) $(OBJS) libft.a libmlx.a -framework OpenGL -framework AppKit
	@echo "\033[92m\nFract-ol successfully compiled!\033[0m"

all:		${NAME}


clean:
	@ ${RM} $(OBJS)
	@ make clean -C ./libft
	@ make clean -C ./mlx
	@echo "\033[0;31mFract-ol successfully cleaned!\033[0m"

fclean:	clean
	@ ${RM} ${NAME}
	@ make fclean -C ./libft
	@ ${RM} libmlx.a
	@ ${RM} libft.a
	@echo "\033[0;31mFract-ol successfully cleaned!\033[0m"

re:			fclean all

fract: all
	@ make clean

.PHONY:		all clean fclean re fract
