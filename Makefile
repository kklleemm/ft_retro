# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/01 10:24:58 by cdeniau           #+#    #+#              #
#    Updated: 2015/11/07 22:37:17 by mzane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = main.cpp Player.cpp Ship.cpp Enemy.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		clang++ -Wall -Werror -Wextra -o $(NAME) $(OBJ) -lncurses

$(OBJ): $(SRC)
		clang++ -Wall -Wextra -Werror -c $(SRC)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
