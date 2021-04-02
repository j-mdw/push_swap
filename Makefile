NAME = push_swap_42

CHECK_DIR_C = src_checker/

CHECK_DIR_O = obj_checker/

CHECK_FILES_C = main.c input_isintarr.c \
				

CHECK_FILES_O = $(addprefix $(CHECK_DIR_O), ${CHECK_FILES_C:c=o})

CHECK_EXE = checker

###

PSWAP_DIR_C = src_pushswap/

PSWAP_DIR_O = obj_pushswap/

PSWAP_FILES_C = main.c \
				dyn_iarray_add.c dyn_iarray_init.c \
				ps_bubble_sort.c pushswap_sort.c\
				ps_fatal.c \
				ps_are_elem_sbs.c ps_rotate_up.c ps_rotate_down.c ps_rotate_top.c ps_push_a.c ps_push_b.c ps_swap.c ps_swap_top.c \
				quick_sort.c

PSWAP_FILES_O = $(addprefix $(PSWAP_DIR_O), $(PSWAP_FILES_C:c=o))

PSWAP_EXE = push_swap

###

STACK_DIR_C = src_stack/

STACK_DIR_O = obj_stack/

STACK_FILES_C = stack_push.c stack_pop.c stack_swap_top_two.c stack_rotate_up.c stack_print.c stack_init.c stack_rotate_down.c stack_ab_init.c stack_ab_fatal.c stack_get_index.c stack_len.c stack_issort.c

STACK_FILES_O = $(addprefix $(STACK_DIR_O), $(STACK_FILES_C:c=o))

H_FILE = push_swap.h

I = -I .\
	-I libft/

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

CC = gcc

C_FLAGS = -Wall -Wextra -Werror $I

RM = rm -f

all: $(NAME)

$(NAME): $(CHECK_EXE) $(PSWAP_EXE)

$(CHECK_EXE): $(CHECK_FILES_O) $(STACK_FILES_O) $(LIBFT)
	$(CC) $^ -o $@

$(CHECK_DIR_O)%.o: $(CHECK_DIR_C)%.c $(H_FILE)
	$(CC) $(C_FLAGS) -c $< -o $@

$(PSWAP_EXE): $(PSWAP_FILES_O) $(STACK_FILES_O) $(LIBFT)
	$(CC) $^ -o $@

$(PSWAP_DIR_O)%.o: $(PSWAP_DIR_C)%.c $(H_FILE)
	$(CC) $(C_FLAGS) -c $< -o $@

$(STACK_DIR_O)%.o: $(STACK_DIR_C)%.c $(H_FILE)
	$(CC) $(C_FLAGS) -c $< -o $@

$(LIBFT):
	make --directory=$(LIBFT_DIR) bonus

clean:
	$(RM) $(CHECK_FILES_O)
	$(RM) $(PSWAP_FILES_O)
	$(RM) $(STACK_FILES_O)
	make --directory=$(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CHECK_EXE)
	$(RM) $(PSWAP_EXE)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
