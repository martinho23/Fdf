# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 17:30:45 by jfarinha          #+#    #+#              #
#    Updated: 2020/12/27 16:40:59 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FILES:=main	draw	utils	hook	load	matrix	matrixOp	transform
BINS:=$(FILES:=.o)
BINS:=$(addprefix srcs/, $(BINS))
INCD:=-I ./includes -I /usr/local/include/ -I /usr/include/X11 -I libft -I minilibx-linux
LIBD:=-L /usr/local/lib/ -L ./libft -L /usr/lib -L minilibx-linux
LIBS:=-lmlx -lXext -lX11 -lft -lm
FLAG:=-Wall -Wextra -Werror -g
LIBFT:= ./libft/libft.a
LIBX:= ./minilibx-linux/mlx

.PHONY:all clean fclean re fullre libclean linux

all:$(LIBFT) $(LIBX) $(NAME)

%.o: %.c
	gcc $(FLAG) -o $@ $(INCD) -c $<

$(NAME): $(BINS)
	gcc $(FLAG) $^ $(LIBD) $(LIBS) -o $@

$(LIBFT):
	make -C ./libft

$(LIBX):
	make -C ./minilibx-linux

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

libclean:
	rm -f $(LIBFT)

re: fclean all

fullre: fclean libclean all
