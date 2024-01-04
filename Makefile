# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 18:16:05 by kmatjuhi          #+#    #+#              #
#    Updated: 2023/12/28 12:12:31 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	push_swap

SRCS	=	push_swap.c list_utiles.c stoi.c operations.c algo.c sort_small_algo.c

OFILES	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
# CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) ${OFILES}
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		make clean -C libft
		$(RM) $(OFILES)
	
fclean: clean
		make fclean -C libft
		$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY: all clean fclean re