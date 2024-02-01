# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:18:12 by aalamino          #+#    #+#              #
#    Updated: 2024/02/01 15:35:41by aalamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CCFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

FILES   = so_long.c keys_control.c map_control.c pathfind.c read_map.c ft_printf.c printf_string_utils.c calc_hex.c get_next_line.c get_next_line_utils.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

lib: $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	cc $(CCFLAGS) $(MLX_FLAGS) $(FILES) -o $(NAME)

.o: .c
	cc $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib
