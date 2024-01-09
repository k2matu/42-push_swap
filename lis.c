/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:48:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/09 12:05:48 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_lis(int *t, int *arr, int max, int i)
{
	int	*lis;

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

static int	*fill_t(int len)
{
	int	i;
	int	*t;

	i = -1;
	t = (int *)malloc(sizeof(int) * len);
	if (!t)
		exit(-1);
	while (i++ < len - 1)
		t[i] = 1;
	return (t);
}

int	*lis(int *arr, int len)
{
	int	*t;
	int	i;
	int	j;
	int	max;
	int	*lis;

	max = 1;
	i = 0;
	t = fill_t(len);
	while (i++ < len - 1)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && t[i] < t[j] + 1)
				t[i] = t[j] + 1;
			if (t[i] > max)
				max = t[i];
			j++;
		}
	}
	lis = create_lis(t, arr, max, i);
	free(t);
	return (lis);
}
