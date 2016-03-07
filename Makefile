# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchristo <ybarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by dchristo          #+#    #+#              #
#    Updated: 2016/03/07 14:49:47 by dchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
PATH_INC = ./libft/

CC = gcc

CFLAGS = -O3 -Wall -Wextra -Werror

SRC = main.c fps.c init.c raycast.c wolf3d_error.c hook.c hook2.c draw.c \
	  draw2.c hook3.c init2.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@echo "\033[0m";
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJS) -lm -L libft/ -lft -lmlx \
		-framework OpenGL -framework AppKit
	@echo "\033[1;5;1;36m";
	@echo "+-----------------------------------+";
	@echo "|                _  __ ____      _  |";
	@echo "|               | |/ _|___ \    | | |";
	@echo "| __      _____ | | |_  __) | __| | |";
	@echo "| \ \ /\ / / _ \| |  _||__ < / _\` | |";
	@echo "|  \ V  V / (_) | | |  ___) | (_| | |";
	@echo "|   \_/\_/ \___/|_|_| |____/ \__,_| |";
	@echo "|                                   |";
	@echo "+-----------------------by dchristo-+";
	@echo "\033[0m";

.PHONY: clean fclean re all

clean:
	make -C libft/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
