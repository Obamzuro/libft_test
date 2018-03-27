# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 11:52:19 by obamzuro          #+#    #+#              #
#    Updated: 2018/03/27 10:56:16 by obamzuro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = toster

FT_LIB_DIR = ./libft/

LIB_NAME = ft

MAIN = main.c

COMPARISON = comp.c

MAIN_HEADER_DIR = ./

$(NAME): all

all:
	find tests -type f -name "*.c" -exec gcc -Wall -Wextra -Werror $(MAIN) $(COMPARISON) -o $(NAME) -I $(FT_LIB_DIR) -I $(MAIN_HEADER_DIR) -L $(FT_LIB_DIR) -l$(LIB_NAME) {} +

allr:
	make re -C $(FT_LIB_DIR)
	find tests -type f -name "*.c" -exec gcc -Wall -Wextra -Werror $(MAIN) $(COMPARISON) -o $(NAME) -I $(FT_LIB_DIR) -I $(MAIN_HEADER_DIR) -L $(FT_LIB_DIR) -l$(LIB_NAME) {} +

alld:
	make re -C $(FT_LIB_DIR)
	find tests -type f -name "*.c" -exec gcc -Wall -Wextra -Werror $(MAIN) $(COMPARISON) -o $(NAME) -I $(FT_LIB_DIR) -I $(MAIN_HEADER_DIR) -L $(FT_LIB_DIR) -l$(LIB_NAME) {} +

run:
	./toster

clean:
	rm -f ./*~ ./*.swp

fclean: clean
	rm -f $(NAME)

cleanr: clean
	make clean -C $(FT_LIB_DIR)

fcleanr: fclean
	make fclean -C $(FT_LIB_DIR)

re: fclean all

red: fclean alld

r: red run

norm:
	norminette
