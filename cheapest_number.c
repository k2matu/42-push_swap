/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:54 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/18 18:46:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack **a, int size)
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

int	count_b_moves(t_stack **b, int pos)
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

int	count_a_moves(t_stack **a, int pos)
{
	t_stack	*temp;
	int		i;
	int		j;
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
	min = find_min_pos(a, size);
	if (i == 0 && pos > min)
	{
		while (temp->pos > pos)
		{
			i--;
			temp = temp->prev;
		}
		i = i + 1;
	}
	if (i == size || i == 0 && pos < min)
	{
		j = i;
		i = 0;
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

static int	count_moves(t_stack **a, t_stack **b, int pos)
{
	int	a_moves;
	int	b_moves;
	int	moves;

	a_moves = count_a_moves(a, pos);
	b_moves = count_b_moves(b, pos);
	if (a_moves == b_moves)
		moves = a_moves;
	else if (a_moves > 0 && b_moves > 0 || a_moves < 0 && b_moves < 0)
	{
		if ((a_moves > b_moves && a_moves > 0) || (a_moves < b_moves && a_moves < 0))
			moves = a_moves;
		else
			moves = b_moves;
	}	
	else
		moves = (b_moves - a_moves);
	if (moves < 0)
		moves *= -1;
	return (moves);
}

int	cheapest_number(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		moves;
	int		min_moves;
	int		min_pos;
	int		count;

	count = count_nodes(*b);
	min_moves = 600;
	temp = *b;
	while (count--)
	{
		moves = count_moves(a, b, temp->pos);
		if (moves < min_moves)
		{
			min_moves = moves;
			min_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (min_pos);
}