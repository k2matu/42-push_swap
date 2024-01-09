/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:50:16 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/09 10:56:25 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **a, int count)
{
	int		*arr;
	int		*l;
	int		i;
	int		j;
	t_stack	*temp;
	t_stack	*b;

	b = NULL;
	i = 0;
	j = 0;
	temp = *a;
	arr = (int *)malloc(sizeof(int) * count);
	while (i < count)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	l = lis(arr, count);
	i = 0;
	while (i < count)
	{
		if (l[j] == (*a)->data)
		{
			*a = (*a)->next;
			j++;
		}
		else
			push(&(*a), &b, 'b');
		i++;
	}
	print(*a);
	print(b);
}