/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:50:16 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/09 12:32:04 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_to_arr(t_stack **a, int count)
{
	int		*arr;
	int		i;
	t_stack	*temp;

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

void	sort_big(t_stack **a, int count)
{
	int		*l;
	int		*arr;
	int		j;
	int		i;
	t_stack	*b;

	b = NULL;
	j = 0;
	arr = lst_to_arr(a, count);
	l = get_lis(arr, count);
	i = 0;
	while (i < count)
	{
		if (l[j] == (*a)->data)
		{
			rotate(&(*a), 'a');
			j++;
		}
		else
			push(&(*a), &b, 'b');
		i++;
	}
	print(*a);
	print(b);
}
