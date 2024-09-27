# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 15:12:37 by joao-rde          #+#    #+#              #
#    Updated: 2024/09/26 19:50:20 by joao-rde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs
INC_DIR = ./includes
SOURCES = push_swap.c $(shell find $(SRC_DIR) -name '*.c')
OBJECTS = $(SOURCES:.c=.o)
LIBFT = libs/libft.a

all: $(NAME) clean

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
