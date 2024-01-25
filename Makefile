# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:18:12 by aalamino          #+#    #+#              #
#    Updated: 2024/01/25 19:16:16 by aalamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CFLAG   = -Lmlx -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra
FILES	= so_long.c keys_control.c map_control.c pathfind.c read_map.c ft_printf.c printf_string_utils.c calc_hex.c get_next_line.c get_next_line_utils.c

OBJS    = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

$(OBJS): $(FILES)
		cc $(CFLAG) -c $(FILES)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY : clean, fclean, re
