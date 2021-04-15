# ====================== VARIABLES ====================== #

NAME = libftprintf.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror

# ====================== FILES ====================== #

SRC =  arg_manager.c
SRC += flag_manager.c
SRC += ft_printf.c
SRC += parser.c
SRC += print.c
SRC += print_utils.c
SRC += str_utils.c

OBJ = $(SRC:c=o)

# ====================== RULES ====================== #

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: re

refresh:
	cp ../src/*c .

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

re: fclean
	-git clone https://github.com/gavinfielder/pft.git
	make fclean
	make refresh
	make $(NAME)
	make clean
	make -C pft

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out
	rm -rf $(SRC)

clean:
	rm -rf $(OBJ)