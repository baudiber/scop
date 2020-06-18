# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baudiber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 14:12:11 by baudiber          #+#    #+#              #
#    Updated: 2020/06/18 16:55:28 by baudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgraph.a
CC = gcc
SRC = srcs/parse_bmp.c \
	  srcs/matrix_operations.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I.
HEADER_H = includes/libgraph.h

all: $(NAME)

$(NAME): $(HEADER_H) $(OBJ)
	@echo "\033[33mCREATING\033[0m $(NAME)" 
	@ar rc $(NAME) $(OBJ)
	@echo "\033[33mINDEXING\033[0m $(NAME)"
	@ranlib $(NAME)
	@echo "\033[32mSUCCESS\033[0m"

%.o: %.c $(HEADER_H)
	@echo "\033[33mCOMPILING\033[0m" $<
	@$(CC) -o  $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	@echo "\033[41mDELETING OBJ FILES...\033[0m"
	@/bin/rm -f $(OBJ)
	@echo "\033[32mSUCCESS\033[0m"

fclean: clean
	@echo "\033[41mDELETING BINARIES...\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[32mSUCCESS\033[0m"

re: fclean all
