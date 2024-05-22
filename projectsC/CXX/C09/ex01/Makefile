LIB_NAME = libft.a
SRCS_PATH = srcs
SRCS = $(wildcard $(SRCS_PATH)/*.c)
INCLUDES_PATH = includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rc $(LIB_NAME) $(OBJS)

%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES_PATH) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
