/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:48:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/16 20:57:31 by kmatjuhi         ###   ########.fr       */
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
	int	*t;
	int	i;

	i = -1;
	t = (int *)malloc(sizeof(int) * len);
	if (!t)
		exit(-1);
	while (i++ < len - 1)
		t[i] = 1;
	return (t);
}

int	*get_lis(int *arr, int len)
{
	int	*t;
	int	*lis;
	int	i;
	int	j;
	int	max;

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
