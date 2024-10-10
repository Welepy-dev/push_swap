# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 12:05:53 by marcsilv          #+#    #+#              #
#    Updated: 2024/10/08 19:39:37 by marcsilv         ###   ########.fr        #
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
VISUALIZER = ./push_swap_visualizer/Makefile

all: $(NAME) visualizer 

$(NAME): $(OBJ_PATHS)
	$(MAKE) -C $(dir $(LIBFT))
	$(CC) $(OBJ_PATHS) -L./libft -lft -o $(NAME)

visualizer:
	$(MAKE) -C $(dir $(VISUALIZER))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I ./libft/includes -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I ./libft/includes -c $< -o $@

clean:
	rm -f $(OBJ_PATHS)
	$(MAKE) -C $(dir $(LIBFT)) clean
	$(MAKE) -C $(dir $(VISUALIZER)) clean  # Clean visualizer

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(dir $(LIBFT)) fclean
	$(MAKE) -C $(dir $(VISUALIZER)) fclean  # Full clean for visualizer

re: fclean all

.PHONY: all clean fclean re visualizer
