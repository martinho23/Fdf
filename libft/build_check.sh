# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    build_check.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 06:19:21 by jfarinha          #+#    #+#              #
#    Updated: 2018/04/19 12:13:18 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
#Variables
FILES=$(find ft_*.c | sort)
COMPILED=$(make re | grep 'gcc -Wall -Werror -Wextra -c' |sort| cut -d ' ' -f 7)
echo "$FILES" > check_FILES
echo "$COMPILED" > check_COMPILED
echo '    Files count:' $(echo "$FILES" | wc -l)
echo ' Compiled count:' $(echo "$COMPILED" | wc -l)
diff check_FILES check_COMPILED
rm -f check_*
