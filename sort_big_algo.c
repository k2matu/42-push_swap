/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:50:16 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/19 11:25:02 by kmatjuhi         ###   ########.fr       */
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

void	push_to_stack_b(int *lis, t_stack **a, t_stack **b, int count)
{
	int	i;
	int	j;
	int frst_pos;

	i = 0;
	j = 0;
	while (i++ < count)
	{
		if (lis[j] == (*a)->data)
		{
			if (j == 0)
				frst_pos = (*a)->pos;
			rotate(&(*a), &(*b), 'a');
			if (lis[j + 1])
				j++;
			else
				break ;
		}
		else
		{
			push(&(*a), &(*b), 'b');
			if ((*b)->pos < (count / 2))
				rotate(&(*a), &(*b), 'b');
		}
	}
	while (i++ < count)
	{
		if ((*a)->pos < frst_pos)
		{
			rotate(&(*a), &(*b), 'a');
			break ;
		}
		else
		{
			push(&(*a), &(*b), 'b');
			if ((*b)->pos < (count / 2))
				rotate(&(*a), &(*b), 'b');
		}
	}
	while (i++ < count)
	{
		if ((*a)->pos < frst_pos && (*a)->pos > (*a)->prev->pos)
			rotate(&(*a), &(*b), 'a');
		else
		{
			push(&(*a), &(*b), 'b');
			if ((*b)->pos < (count / 2))
				rotate(&(*a), &(*b), 'b');
		}
	}
}

void	sort_big(t_stack **a, int count)
{
	t_stack	*b;
	int		*lis;
	int		*arr;
	int		*backup;
	int		min_pos;

	b = NULL;
	arr = lst_to_arr(a, count);
	backup = lst_to_arr(a, count);
	quick_sort(arr, count);
	fill_stack_pos(&(*a), arr, count);
	if (count < 6)
	{
		if (count == 5)
			push(&(*a), &b, 'b');
		push(&(*a), &b, 'b');
		sort_three(&(*a));
	}
	if (count > 5)
	{
		lis = get_lis(backup, count);
		push_to_stack_b(lis, &(*a), &b, count);
		free(lis);
	}
	free(arr);
	while (b)
	{
		min_pos = cheapest_number(&(*a), &b);
		push_back(&(*a), &b, min_pos);
	}
	rotate_a_back(&*a, count_nodes(*a));
	// if (check_sorted(a) == count)
	// 	printf("STACK SORTED");
}
