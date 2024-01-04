/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:11:14 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/28 13:05:29 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->prev->data)
		swap(&(*a), 'a');
	else if ((*a)->data > (*a)->next->data \
	&& (*a)->next->data < (*a)->prev->data)
		rotate(&(*a), 'a');
	else if ((*a)->data > (*a)->next->data)
	{
		swap(&(*a), 'a');
		reverse_rotate(&(*a), 'a');
	}
	else if ((*a)->data > (*a)->prev->data)
		reverse_rotate(&(*a), 'a');
	else if ((*a)->next->data > (*a)->prev->data)
	{
		swap(&(*a), 'a');
		rotate(&(*a), 'a');
	}
	return ;
}

void	rotate_back(t_stack **a, int count, int min)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = (*a);
	while (temp->data != min)
	{
		i++;
		temp = temp->next;
	}
	while ((*a)->data != min)
	{
		if (i < count / 2)
			rotate(&(*a), 'a');
		else
			reverse_rotate(&(*a), 'a');
	}
}

void	sort_rest(t_stack **a, t_stack *b, int count)
{
	long	min;
	long	max;

	min = (*a)->data;
	max = (*a)->prev->data;
	while (b != NULL)
	{
		if (b->data < min && (*a)->data == min && (*a)->prev->data == max)
		{
			push(&b, &(*a), 'a');
			min = (*a)->data;
		}
		else if (b->data > max && (*a)->data == min && (*a)->prev->data == max)
		{
			push(&b, &(*a), 'a');
			max = (*a)->data;
		}
		else if (b->data < (*a)->data && b->data > (*a)->prev->data)
			push(&b, &(*a), 'a');
		else
			rotate(&(*a), 'a');
	}
	rotate_back(&(*a), count, min);
}

void	sort_five(t_stack **a, int count)
{
	t_stack	*b;

	b = NULL;
	if (count == 5)
		push(&(*a), &b, 'b');
	push(&(*a), &b, 'b');
	sort_three(&(*a));
	sort_rest(&(*a), b, count);
}
