# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 13:44:49 by jfarinha          #+#    #+#              #
#    Updated: 2018/07/18 19:49:41 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
BINS=$(patsubst %, %.o, $(FILES))
FLAGS=-Wall -Werror -Wextra
SRCS=$(patsubst %, %.c, $(FILES))
FILES=	ft_memset	ft_memcpy	ft_memccpy	ft_memmove	ft_memchr	ft_memcmp\
		ft_memalloc	ft_memdel	ft_bzero\
		ft_atoi		ft_itoa		ft_uimtoa_base	ft_uimtoalen_base\
		ft_imtoalen_base		ft_atoim\
		ft_toupper	ft_tolower\
		ft_isspace	ft_isdigit	ft_islower	ft_isupper	ft_isalpha	ft_isalnum\
		ft_isascii	ft_isprint	ft_strisint\
		ft_getindice	get_next_line	ft_wcharlen\
		ft_strlen	ft_strdup	ft_strcpy	ft_strncpy	ft_strcat	ft_strncat\
		ft_strlcat	ft_strchr	ft_strrchr	ft_strstr	ft_strnstr	ft_strcmp\
		ft_strncmp	ft_strnew	ft_strdel	ft_strclr	ft_striter	ft_striteri\
		ft_strmap	ft_strmapi	ft_strequ	ft_strnequ	ft_strsub	ft_strjoin\
		ft_strtrim	ft_strsplit	ft_strfreejoin	ft_wstrlen\
		ft_strfindoc\
		ft_putchar	ft_putstr	ft_putendl	ft_putnbr	ft_putchar_fd\
		ft_putstr_fd	ft_putendl_fd	ft_putnbr_fd	ft_putwstr_fd\
		ft_putnwstr_fd	ft_putnwstr	ft_putwstr	ft_putnstr	ft_putnstr_fd\
		ft_lstnew	ft_lstdelone	ft_lstdel	ft_lstadd	ft_lstiter\
		ft_lstmap

%.o:%.c
	gcc $(FLAGS) -c -I. $<

$(NAME): $(BINS)
	ar -rc $(NAME) $^
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc $(FLAGS) -fPIC -c -I. $(SRCS)
	gcc -shared -o libft.so $(BINS)
