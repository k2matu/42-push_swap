/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:34:34 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/19 12:18:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_pos(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			swap_pos(&arr[j], &arr[i]);
			i++;
		}
		j++;
	}
	swap_pos(&arr[i], &arr[high]);
	return (i);
}

void	quicksort(int *arr, int low, int high)
{
	int	pi;

	pi = 0;
	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}
