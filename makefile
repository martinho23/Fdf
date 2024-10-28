# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 17:30:45 by jfarinha          #+#    #+#              #
#    Updated: 2024/10/28 22:00:17 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FILES:=main	draw	utils	hook	load	matrix	matrixOp	transform \
	   screenBuffer	line	math	vector
BINS:=$(FILES:=.o)
BINS:=$(addprefix srcs/, $(BINS))
INCD:=-I ./include -I /usr/local/include/ -I /usr/include/X11 -I libft -I MLX42/include
LIBD:=-L /usr/local/lib/ -L ./libft -L /usr/lib -L ./MLX42/build
LIBS:=-lmlx -lXext -lX11 -lft -lm
FLAG:=-Wall -Wextra -Werror -g
LIBFT:= ./libft/libft.a
LIBX:= ./MLX42/build/libmlx42.a

.PHONY:all clean fclean re fullre libclean linux run

all:$(LIBFT) $(LIBX) $(NAME)

%.o: %.c
	gcc $(FLAG) -o $@ $(INCD) -c $<

$(NAME): $(BINS)
	gcc $(FLAG) $^ $(LIBD) $(LIBS) -o $@

$(LIBFT):
	make -C ./libft

$(LIBX):
	cmake -S MLX42 -B build
	cmake --build MLX42/build --parallel --config Debug

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

libclean:
	rm -f $(LIBFT)
	rm -f $(LIBX)

re: fclean all

fullre: fclean libclean all

run: all
	./fdf maps/42.fdf
