# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baudiber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:30:36 by baudiber          #+#    #+#              #
#    Updated: 2020/11/02 22:21:26 by baudibert        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	scop

SRC_DIR		=	./srcs
INC_DIR		=	./includes
OBJ_DIR		=	./objs
LIBFT_DIR	=	./libft

SRC			=	scop.c							\
				init.c							\
				engine/run.c					\
				engine/shaders.c 				\
				inputs/process_inputs.c 		\
				libgraph/parse_bmp.c 			\
				libgraph/matrix_ops.c 			\
				libgraph/vec_ops.c 				\
				libgraph/utils.c 			    \
				parser/read_file.c 				\
				parser/data_mallocs.c			\
				parser/lists.c					\
				parser/parse_line.c 			\
				parser/parse_faces.c 			\
				parser/process_data.c 			\
				parser/process_face_data.c 		\
				parser/vert_creation.c 			\
				parser/normalize_mesh.c         \
				parser/parsing.c 				\

R			=	\033[31m
G			=	\033[32m
B			=	\033[34m
W			=	\033[0m
O			=	\033[33m

FLAGS		=	-Wall -Werror -Wextra -g
INCLUDES	=	-I$(INC_DIR) -I$(LIBFT_DIR) `pkg-config --cflags glfw3`
HEADER_H	=	$(INC_DIR)/$(NAME).h

OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

ifeq ($(shell uname -s), Darwin)
   SRC 		    +=  main_mac.c 					\
					init_mac.c			\
					parser/shaders_mac.c
   LIBS			=	-L $(LIBFT_DIR) -lft `pkg-config --static --libs glfw3 glew` -framework OpenGL -framework Appkit
   CC 			=	gcc
else ifeq ($(shell uname -s), Linux) 
   SRC 		    +=  main_linux.c 				\
					init_linux.c			\
					parser/shaders_linux.c
   LIBS			=	-L $(LIBFT_DIR) -lft `pkg-config --static --libs glfw3 glew` -lGL -lX11 -lpthread -lXrandr -lXi -ldl
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
	@mkdir -p $@/libgraph

lib:
	@make -C $(LIBFT_DIR)

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

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all art lib clean fclean re
