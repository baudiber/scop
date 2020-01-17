# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baudiber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:30:36 by baudiber          #+#    #+#              #
#    Updated: 2020/01/13 12:35:32 by baudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	scop

SRC_DIR		=	./srcs
INC_DIR		=	./includes
OBJ_DIR		=	./objs
LIBFT_DIR	=	./libft

SRC			=	main.c							\
				glad.c							\
				engine/init.c					\
				engine/run.c					\
				parser/read_file.c

R			=	\033[31m
G			=	\033[32m
B			=	\033[34m
W			=	\033[0m
O			=	\033[33m

CC 			=	gcc
FLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I $(INC_DIR) `sdl2-config --cflags`
HEADER_H	=	$(INC_DIR)/$(NAME).h
LIBS		=	-L $(LIBFT_DIR) -lft `sdl2-config --libs`
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: art $(NAME)

$(NAME): lib $(HEADER_H) $(OBJ)
	@$(CC)  $(OBJ) -o $(NAME) $(LIBS)
	@echo "$(NAME) executable $(G)created$(W)."

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c $(HEADER_H) | $(OBJ_DIR)
	@echo "$(O)COMPILING$(W)" $<
	@$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

$(OBJ_DIR):
	@mkdir -p $@ 
	@mkdir -p $@/parser
	@mkdir -p $@/engine

lib:
	@make -C $(LIBFT_DIR)

art:
	@echo " ███████╗ ██████╗ ██████╗ ██████╗"
	@echo " ██╔════╝██╔════╝██╔═══██╗██╔══██╗"
	@echo " ███████╗██║     ██║   ██║██████╔╝"
	@echo " ╚════██║██║     ██║   ██║██╔═══╝"
	@echo " ███████║╚██████╗╚██████╔╝██║"
	@echo " ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all art lib clean fclean re