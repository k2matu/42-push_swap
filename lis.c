/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:48:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/09 10:11:06 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lis(int *arr, int len)
{
	int t[len];
	int *lis;
	int j = 0;
	int max = 1;
	int i = -1;
	
	while (i++ < len - 1)
		t[i] = 1;
	i = 0;
	while (i++ < len - 1)
	{
		while (j < i)
		{
			if (arr[j] < arr[i] && t[i] < t[j] + 1)
				t[i] = t[j] + 1;
			if (t[i] > max)
				max = t[i];
			j++;
		}
		j = 0;
	}
	lis = (int *)malloc(sizeof(int) * max);
	while (max != 0)
	{
		if (t[i] == max)
		{
			lis[max - 1] = arr[i];
			max--;
		}
		i--;
	}
	return (lis);
}
