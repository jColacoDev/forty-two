CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIB_DIR = ../../ft_printf
LIBFTPRINTF = $(LIB_DIR)/libftprintf.a
SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = test_ft_printf

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTPRINTF)
	$(MAKE) clean
	valgrind ./test_ft_printf --leak-check=full --show-leak-kinds=all

$(LIBFTPRINTF):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) fclean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

all: $(NAME)
