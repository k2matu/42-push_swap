/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:50:16 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/19 19:25:58 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_to_arr(t_stack **a, int count)
{
	t_stack	*temp;
	int		*arr;
	int		i;

	i = 0;
	temp = *a;
	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
	{
		free_stack(a);
		exit (-1);
	}
	while (i < count)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}

void	fill_stack_pos(t_stack **a, int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (arr[j] != (*a)->data)
			j++;
		if (arr[j] == (*a)->data)
			(*a)->pos = j;
		*a = (*a)->next;
		j = 0;
		i++;
	}
}

static void	push_stack_b_scnd(t_stack **a, t_stack **b, int count, int frst_pos)
{
	int	j;

	j = 0;
	while ((*a)->pos != frst_pos)
	{
		if (((*a)->pos < frst_pos && j == 0) || \
		((*a)->pos < frst_pos && (*a)->pos > (*a)->prev->pos))
		{
			rotate(&(*a), &(*b), 'a');
			j = 1;
		}
		else
		{
			push(&(*a), &(*b), 'b');
			if ((*b)->pos < (count / 2))
				rotate(&(*a), &(*b), 'b');
		}
	}
}

void	push_to_stack_b(int *lis, t_stack **a, t_stack **b, int count)
{
	int	i;
	int	j;
	int	frst_pos;

	i = 0;
	j = 0;
	while (i++ < count)
	{
		if (lis[j] == (*a)->data)
		{
			if (j == 0)
				frst_pos = (*a)->pos;
			rotate(&(*a), &(*b), 'a');
			if (!lis[j + 1])
				break ;
			j++;
		}
		else
		{
			push(&(*a), &(*b), 'b');
			if ((*b)->pos < (count / 2))
				rotate(&(*a), &(*b), 'b');
		}
	}
	push_stack_b_scnd(&(*a), &(*b), count, frst_pos);
}
