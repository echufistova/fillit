# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 15:59:16 by ychufist          #+#    #+#              #
#    Updated: 2018/07/01 17:12:03 by amartyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./backtracking.c ./count_hash.c ./cut_ttrmns.c ./field.c ./ft_arrfree.c \
	  ./ft_memalloc.c ./ft_memcpy.c ./ft_memset.c ./ft_putendl.c ./ft_sqrt.c \
	 ./ft_putstr.c ./ft_strjoin.c ./ft_strlen.c ./ft_strsplit.c ./ft_strsub.c \
	./ft_ttlist_new.c ./insrt.c ./main.c ./new_valid.c ./symbols.c

OUT = $(SRC:.c=.o)

H = ./fillit.h

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c $(HEADER)
	gcc $(FLAGS) -o $@ $<

$(NAME): $(OUT)
	gcc -o $(NAME) $(OUT)

clean:
	/bin/rm -f $(OUT)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
