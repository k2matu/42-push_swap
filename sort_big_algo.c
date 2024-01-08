/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:50:16 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/08 12:26:41 by kmatjuhi         ###   ########.fr       */
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
	while (i < count)
	{
		if (l[j] == (*a)->data)
		{
			
		}
	}
}