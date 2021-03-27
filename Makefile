CC = gcc

C_FLAGS = -Wall -Wextra -Werror

NAME = push_swap

CHECK_DIR_C = src_checker/

CHECK_DIR_O = obj_checker/

CHECK_FILES_C = main.c

CHECK_FILES_O = $(addprefix $(CHECK_DIR_O), ${CHECK_FILES_C:c=o})

RM = rm -f

CHECK_EXE = checker

H_FILE = push_swap.h

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(CHECK_EXE)

$(CHECK_EXE): $(CHECK_FILES_O) $(LIBFT)
	$(CC) $^ -o $@

$(CHECK_DIR_O)%.o: $(CHECK_DIR_C)%.c $(H_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make --directory=$(LIBFT_DIR) bonus

clean:
	$(RM) $(CHECK_FILES_O)
	make --directory=$(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CHECK_EXE)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
