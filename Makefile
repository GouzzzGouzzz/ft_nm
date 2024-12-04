NAME=ft_nm
CFLAGS= -g #-Wall -Werror -Wextra
CC=clang
OBJ_DIR=obj
SRC_DIR=src
MANDATORY= src/main.c\
	src/debug.c\
	src/show_info.c\

LIBFT=-Llibft/ -lft
LIBFT_OBJ=./libft/obj/*.o

OBJ=$(MANDATORY:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(MAKE) -C ./libft/ all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_OBJ)

clean:
	$(MAKE) -C ./libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
