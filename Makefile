# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:18:12 by aalamino          #+#    #+#              #
#    Updated: 2024/01/12 11:18:13 by aalamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long.a
CFLAG   = -framework OpenGL -framework AppKit -Wall -Werror -Wextra
FILES	= so_long.c keys_control.c map_control.c pathfind.c read_map.c

OBJ    = $(FILES:.c=.o)
B_OBJS  = $(FILES_BO:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
        ar rc $(NAME) $(OBJS)

$(OBJS): $(FILES)
        gcc $(CFLAG) -c $(FILES)

bonus: $(OBJS) $(B_OBJS)
        ar rc $(NAME) $(OBJS) $(B_OBJS)
clean:
        @rm -f $(OBJS) $(B_OBJS)

fclean: clean
        @rm -f $(NAME)

re: fclean all

.PHONY : clean, fclean, re
