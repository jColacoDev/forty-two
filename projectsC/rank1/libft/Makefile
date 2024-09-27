# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 15:12:37 by joao-rde          #+#    #+#              #
#    Updated: 2024/09/26 19:49:53 by joao-rde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS= -Wall -Wextra -Werror
INC_DIR = ./includes
SRC_DIR = ./ft_printf
SOURCES = $(shell ls *.c) $(shell find $(SRC_DIR) -name '*.c')

OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
