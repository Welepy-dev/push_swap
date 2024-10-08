# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 12:05:53 by marcsilv          #+#    #+#              #
#    Updated: 2024/10/06 12:18:25 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs

INC_DIR = includes
OBJ_DIR = .
HEADER = push_swap.h

SRC_FILES =		./moves/push.c ./moves/rotate.c ./moves/swap.c ./sort/aproximity_sort.c ./sort/lazy_aproximity.c ./sort/lazy_sort.c \
				./sort/tiny_sort.c ./utils/utils_2.c ./utils/utils_3.c ./utils/utils_1.c ./init.c ./push_swap.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

LIBFT = ./libft/Makefile

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	$(MAKE) -C $(dir $(LIBFT))
	$(CC) $(OBJ_PATHS) $ -L./libft -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I mlx_linux -I ./libft/includes -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I mlx_linux -I ./libft/includes -c $< -o $@

clean:
	rm -f $(OBJ_PATHS)
	$(MAKE) -C $(dir $(LIBFT)) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(dir $(LIBFT)) fclean

re: fclean all

.PHONY: all clean fclean re
