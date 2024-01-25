# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:18:12 by aalamino          #+#    #+#              #
#    Updated: 2024/01/25 19:31:51 by aalamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAG   = -Wall -Werror -Wextra
FILES	= so_long.c keys_control.c map_control.c pathfind.c read_map.c ft_printf.c printf_string_utils.c calc_hex.c get_next_line.c get_next_line_utils.c
MLX_LIB = mlx/libmlx.a

OBJS    = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
		cc $(CFLAG) -o $(NAME) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit

$(MLX_LIB):
		make -C mlx

$(OBJS): $(FILES)
		cc $(CFLAG) -c $< -o $@

clean:
		@rm -f $(OBJS)
		make -C mlx clean

fclean: clean
		@rm -f $(NAME)
		make -C mlx clean

re: fclean all

.PHONY: clean fclean re
