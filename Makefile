# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/28 13:32:34 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/03/29 19:10:07 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRC = sources/fdf.c				\
	  sources/parse.c			\
	  sources/mlx_manager.c		\
	  sources/coord_manager.c	\
	  sources/draw.c			\


OBJECTS = $(SRC:.c=.o)

LIB = libft.a

LIBARRAY = libarray.a

HEADS = -I ./includes			\
		-I ./libft/includes		\
		-I ./ft_array			\

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@(make -C libft)

$(LIBARRAY):
	@(make -C ft_array)

$(NAME): $(LIB) $(LIBARRAY) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB) ft_array/$(LIBARRAY) \
		./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
	@echo "$(BLUE)$(NAME)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "Compiling $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(FLAGS) $(HEADS) -o $@ -c $?
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft
	@make clean -C ft_array

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_array

re: fclean all
