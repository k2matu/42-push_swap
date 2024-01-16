/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:54 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/16 19:28:24 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack **a, int size)
{
	t_stack	*temp;
	int		min;
	int		i;

	i = 0;
	temp = *a;
	min = temp->pos;
	while (i < size)
	{
		if (min > temp->pos)
			min = temp->pos;
		temp = temp->next;
		i++;
	}
	return (min);
}

static int	count_b_moves(t_stack **b, int pos)
{
	t_stack	*temp;
	int		i;
	int		size;

	i = 0;
	temp = *b;
	size = count_nodes(*b);
	while (temp->pos != pos)
	{
		i++;
		temp = temp->next;
	}
	if (i > size / 2)
		i = i - size;
	return (i);
}

static int	count_a_moves(t_stack **a, int pos)
{
	t_stack	*temp;
	int		i;
	int		min;
	int		size;

	i = 0;
	temp = *a;
	size = count_nodes(*a);
	while (temp->pos < pos && i < size)
	{
		i++;
		temp = temp->next;
	}
	if (i == 0 || i == size)
	{
		i = 0;
		min = find_min_pos(a, size);
		while (temp->pos != min)
		{
			i++;
			temp = temp->next;
		}
	}
	if (i > size / 2)
		i = i - size;
	return (i);
}

static int	moves(t_stack **a, t_stack **b, int pos)
{
	int	a_moves;
	int	b_moves;

	a_moves = count_a_moves(a, pos);
	b_moves = count_b_moves(b, pos);
	printf("a: %d, and b: %d\n", a_moves, b_moves);
	return (0);	
}

int	cheapest_number(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;
	int		count;

	i = 0;
	count = count_nodes(*b);
	temp = *b;
	while (i < count)
	{
		moves(a, b, 9);
		// send temp into to find cheapeast number in b stack and a stack;
		i++;
	}
	// go through *b stack every time to count the cheapest move
	// count cheapest move from *b stack to the top and sum it with moves from a stack. and save it (save moves and pos number	
	
	// return cheapest number;
	return (0);
}