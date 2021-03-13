# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 11:51:51 by mhadad            #+#    #+#              #
#    Updated: 2021/01/06 16:46:03 by mhadad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = src/ctype/ft_isalnum.c \
src/ctype/ft_isalpha.c \
src/ctype/ft_isascii.c \
src/ctype/ft_isdigit.c \
src/ctype/ft_isprint.c \
src/stdio/ft_putchar_fd.c \
src/stdio/ft_putendl_fd.c \
src/stdio/ft_putnbr_fd.c \
src/stdio/ft_putstr_fd.c \
src/stdlib/ft_atoi.c \
src/stdlib/ft_calloc.c \
src/stdlib/ft_itoa.c \
src/string/ft_bzero.c \
src/string/ft_memccpy.c \
src/string/ft_memchr.c \
src/string/ft_memcmp.c \
src/string/ft_memcpy.c \
src/string/ft_memmove.c \
src/string/ft_memset.c \
src/string/ft_split.c \
src/string/ft_strchr.c \
src/string/ft_strdup.c \
src/string/ft_strjoin.c \
src/string/ft_strlcat.c \
src/string/ft_strlcpy.c \
src/string/ft_strlen.c \
src/string/ft_strmapi.c \
src/string/ft_strncmp.c \
src/string/ft_strnstr.c \
src/string/ft_strrchr.c \
src/string/ft_strtrim.c \
src/string/ft_substr.c \
src/string/ft_tolower.c \
src/string/ft_toupper.c \

SRC_BONUS = src/chained_list/ft_lstadd_back.c \
src/chained_list/ft_lstadd_front.c \
src/chained_list/ft_lstclear.c \
src/chained_list/ft_lstdelone.c \
src/chained_list/ft_lstiter.c \
src/chained_list/ft_lstlast.c \
src/chained_list/ft_lstmap.c \
src/chained_list/ft_lstnew.c \
src/chained_list/ft_lstsize.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:c=o)
BONUS = $(SRC_BONUS:c=o)


%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f bonus

re: fclean all

bonus: $(OBJ) $(BONUS)
	ar -rcs $(NAME) $(OBJ) $(BONUS)
	touch bonus

.PHONY: all, clean, fclean, re
