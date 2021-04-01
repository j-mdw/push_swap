# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaydew <jmaydew@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/14 05:11:51 by jmaydew           #+#    #+#              #
#    Updated: 2021/03/27 16:37:52 by jmaydew          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

REG_SRC_FILES = ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_atoi.c ft_memccpy.c \
ft_putstr_fd.c ft_strncmp.c ft_bzero.c ft_memchr.c ft_split.c ft_strnstr.c \
ft_calloc.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_isalnum.c ft_memcpy.c \
ft_strdup.c ft_strtrim.c ft_isalpha.c ft_memmove.c ft_strjoin.c ft_substr.c \
ft_isascii.c ft_memset.c ft_strlcat.c ft_tolower.c ft_isdigit.c \
ft_putchar_fd.c ft_strlcpy.c ft_toupper.c ft_isprint.c ft_putendl_fd.c \
ft_strlen.c

BONUS_SRC_FILES = ft_lstadd_back.c ft_lstnew.c ft_lstlast.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c \
ft_free_strarr_bonus.c ft_free_strnarr_bonus.c ft_isblank_bonus.c  \
ft_lstfind_bonus.c  ft_list_remove_if_bonus.c  ft_putstrarr_bonus.c  \
ft_strcmp_bonus.c  ft_strcpy_bonus.c  ft_strfind_bonus.c ft_isnumber_bonus.c \
ft_atoi_overflow_bonus.c ft_putintarr_bonus.c ft_intarr_dup_bonus.c \
ft_intarr_min_bonus.c ft_swap_int_bonus.c

REG_OBJ_FILES := ${REG_SRC_FILES:c=o}

BONUS_OBJ_FILES := ${BONUS_SRC_FILES:c=o}

ifdef WITH_BONUS
	OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
	SRC_FILES = $(REG_SRC_FILES) $(BONUS_SRC_FILES)
else
	OBJ_FILES = $(REG_OBJ_FILES)
	SRC_FILES = $(REG_SRC_FILES)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES) libft.h
	$(CC) $(CFLAGS) -c $(SRC_FILES)

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all bonus clean fclean re
