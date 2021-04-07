# ====================== VARIABLES ====================== #

NAME = libftprintf.a

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror

# ====================== FILES ====================== #

SRC = ft_printf.c
SRC += parser.c
SRC += parser_utils.c
SRC += str_utils.c
SRC += arg_manager.c
SRC += print.c

OBJ = $(SRC:c=o)

# ====================== RULES ====================== #

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)

refresh:
	cp ../src/*c .

$(NAME): refresh $(OBJ)
	ar -rcs $(NAME) $(OBJ)


re: fclean all
	make clean

exe: main
	@echo "\n"
	@./a.out
	
main: re
	$(CC) $(CFLAGS) $(DEF) main.c libftprintf.a

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out
	rm -rf $(SRC)

clean:
	rm -rf $(OBJ)