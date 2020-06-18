# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baudiber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:47:49 by baudiber          #+#    #+#              #
#    Updated: 2020/06/18 14:18:53 by baudiber         ###   ########.fr        #
#    Updated: 2018/04/28 17:50:49 by baudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_islower.c \
	  ft_isupper.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_intlen.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_tabnew.c \
	  ft_puttab.c \
	  ft_putints.c \
	  ft_tabintnew.c \
	  ft_tablen.c \
	  ft_strsort.c \
	  ft_lstlen.c \
	  ft_intsort.c \
	  ft_putmatrix.c \
	  ft_freetab.c \
	  ft_freematrix.c \
	  ft_strjoinfree.c \
	  ft_matrixlen.c \
	  ft_newlst.c \
	  ft_strchr_sec.c \
	  get_next_line.c \
	  ft_get_hexa.c \
	  ft_getcolor.c \
	  ft_strtoui.c \
	  ft_atoi_base.c \
	  ft_itoa_base.c \
	  ft_utoa_base.c \
	  ft_swap.c \
	  ft_atod.c \
	  ft_atol.c \
	  ft_longlen.c \
	  ft_pow.c
	

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I.
HEADER_H = libft.h

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
