# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 17:30:45 by jfarinha          #+#    #+#              #
#    Updated: 2024/10/23 21:19:37 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FILES:=main	draw	utils	hook	load	matrix	matrixOp	transform \
	   screenBuffer	line	math	vector
BINS:=$(FILES:=.o)
BINS:=$(addprefix srcs/, $(BINS))
INCD:=-I ./include -I /usr/local/include/ -I /usr/include/X11 -I libft -I minilibx-linux
LIBD:=-L /usr/local/lib/ -L ./libft -L /usr/lib -L minilibx-linux
LIBS:=-lmlx -lXext -lX11 -lft -lm
FLAG:=-Wall -Wextra -Werror -ggdb
LIBFT:= ./libft/libft.a
LIBX:= ./minilibx-linux/mlx

.PHONY:all clean fclean re fullre libclean linux run

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

run: all
	./fdf maps/42.fdf
