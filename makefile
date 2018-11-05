# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 17:30:45 by jfarinha          #+#    #+#              #
#    Updated: 2018/11/05 10:43:30 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FILES:=main	draw	utils	hook
BINS:=$(FILES:=.o)
BINS:=$(addprefix srcs/, $(BINS))
INCD:=-I ./includes -I /usr/local/include/
LIBD:=-L /usr/local/lib/ -L ./libft
LLIBS:=-lmlx -lXext -lX11 -lft -lm
MLIBS:=-lmlx -framework OpenGl -framework AppKit
FLAG:=-Wall -Wextra -Werror
LIBFT:= ./libft/libft.a

.PHONY:all clean fclean re fullre libclean linux

all:$(LIBFT) $(NAME)

%.o: %.c
	gcc $(FLAG) -o $@ $(INCD) -c $<

$(NAME): $(BINS)
	gcc $(FLAG) $^ $(LIBD) $(MLIBS) -o $@

$(LIBFT):
	make -C ./libft

linux:
	gcc $(FLAG) $^ $(LIBD) $(LLIBS) -o $@

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

libclean:
	rm -f $(LIBFT)

re: fclean all

fullre: fclean libclean all
