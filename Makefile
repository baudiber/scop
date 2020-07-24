# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baudiber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:30:36 by baudiber          #+#    #+#              #
#    Updated: 2020/07/24 10:58:11 by baudibert        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	scop

SRC_DIR		=	./srcs
INC_DIR		=	./includes
OBJ_DIR		=	./objs
LIBFT_DIR	=	./libft
LIBGRAPH_DIR =  ./libgraph

SRC			=	main.c							\
				glad.c							\
				engine/init.c					\
				engine/run.c					\
				inputs/process_inputs.c 		\
				parser/shaders.c 				\
				parser/read_file.c 				\
				parser/process_data.c 			\
				parser/parsing.c 				\
				engine/matrix_ops.c

R			=	\033[31m
G			=	\033[32m
B			=	\033[34m
W			=	\033[0m
O			=	\033[33m

FLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I$(INC_DIR) `pkg-config --cflags glfw3`
HEADER_H	=	$(INC_DIR)/$(NAME).h

OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
ifeq ($(shell uname -s), Darwin)
   LIBS		=	-L $(LIBFT_DIR) -lft -L $(LIBGRAPH_DIR) -lgraph `pkg-config --static --libs glfw3` -framework OpenGL -framework Appkit
   CC 			=	gcc
else ifeq ($(shell uname -s), Linux) 
	LIBS		=	-L $(LIBFT_DIR) -lft -L $(LIBGRAPH_DIR) -lgraph `pkg-config --static --libs glfw3` -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	CC 			=	clang
endif

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
	@mkdir -p $@/inputs

lib:
	@make -C $(LIBFT_DIR)
	@make -C $(LIBGRAPH_DIR)

art:
	@echo " ███████╗ ██████╗ ██████╗ ████████╗"
	@echo " ██╔════╝██╔════╝██╔═══██╗██╔═══██║"
	@echo " ███████╗██║     ██║   ██║████████║"
	@echo " ╚════██║██║     ██║   ██║██╔═════╝"
	@echo " ███████║╚██████╗╚██████╔╝██║"
	@echo " ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBGRAPH_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBGRAPH_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all art lib clean fclean re
