# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 17:30:45 by jfarinha          #+#    #+#              #
#    Updated: 2018/11/04 20:08:09 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FILES:=main	draw	utils	hook
BINS:=$(FILES:=.o)
BINS:=$(addprefix srcs/, $(BINS))
INCD:=-I ./includes -I /usr/include/X11/ -I /usr/local/include/
LIBD:=-L/usr/local/lib/ -L./libft
LIBS:=-lmlx -lXext -lX11 -lft -lm
FLAG:=-Wall -Wextra -Werror

.PHONY:all clean fclean re

all:$(NAME)

%.o: %.c
	gcc $(FLAG) -o $@ $(INCD) -c $<

$(NAME): $(BINS)
	gcc $(FLAG) $^ $(LIBD) $(LIBS) $(INCD) -o $@

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all
