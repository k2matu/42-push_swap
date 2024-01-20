# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 18:16:05 by kmatjuhi          #+#    #+#              #
#    Updated: 2024/01/20 18:47:54 by kmatjuhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	push_swap
CHECK	=	checker

SRCS	=	push_swap.c list_utils.c stoi.c operations.c sort_utils.c lis.c \
			quick_sort.c cheapest_number.c check_sorted.c push_back.c count_moves.c
CHECK_SRCS	=	$(wildcard *.c) checker.c

OBJS	=	$(SRCS:.c=.o)
CHECK_OBJS	=	$(CHECK_SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME) $(CHECK)

bonus: $(CHECK)

$(NAME): $(LIBFT) ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
$(CHECK): $(LIBFT) ${CHECK_OBJS}
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(LIBFT) -o $(CHECK)

$(LIBFT):
	make -C ./libft

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		make clean -C libft
		$(RM) $(OBJS)
		$(RM) $(CHECK_OBJS)
	
fclean: clean
		make fclean -C libft
		$(RM) $(NAME) $(OBJS) $(CHECK_OBJS)

re: fclean all

.PHONY: all clean fclean re