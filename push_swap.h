/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:32:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/16 20:55:32 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			data ;
	int				pos ;
	struct s_stack	*prev ;
	struct s_stack	*next ;
}	t_stack;

t_stack		*add_new(long data);
t_stack		*stoi(int argc, char **argv);
void		add_front(t_stack **lst, t_stack *new);
void		add_back(t_stack **lst, t_stack *new);
void		free_stack(t_stack **stack);
void		algo(t_stack **a);
void		swap(t_stack **lst, char c);
void		push(t_stack **src, t_stack **dest, char c);
void		rotate(t_stack **a_lst, t_stack **b_lst, char c);
void		reverse_rotate(t_stack **a_lst, t_stack **b_lst, char c);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, int count);
void		rotate_a_back(t_stack **a, int count, int min);
void		sort_big(t_stack **a, int count);
void		print(t_stack *stack);
void		quick_sort(int *arr, int count);
int			*get_lis(int *arr, int len);
int			count_nodes(t_stack *stack);
int			cheapest_number(t_stack **a, t_stack **b);
int			check_sorted(t_stack **a);
void		free_arr(char **value);

#endif