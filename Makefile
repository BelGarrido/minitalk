# Path to ft_printf
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR) 

#------------------------------------

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_UTILS = minitalk_utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

all: $(PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# Server build rule
$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF_INC) $(PRINTF_LIB) -o $(NAME_SERVER)

# Client build rule
$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) $(PRINTF_INC) $(PRINTF_LIB) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(PRINTF_INC) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
