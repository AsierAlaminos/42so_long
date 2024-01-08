# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 15:26:57 by acalin-b          #+#    #+#              #
#    Updated: 2024/01/08 17:48:11 by aalamino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAG	= -Wall -Werror -Wextra
FILES		= ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_isalnum.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_memcmp.c ft_memchr.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c get_next_line.c get_next_line_utils.c ft_printf.c printf_string_utils.c calc_hex.c

FILES_BO	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	= $(FILES:.c=.o)
B_OBJS	= $(FILES_BO:.c=.o)

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

