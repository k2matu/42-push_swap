/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:48:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/08 10:48:52 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void print(int *c)
{
	int i = -1;
	while (i++ < 5)
		printf("value %d is = %d\n", i, c[i]);
}

int main()
{
	int len = 12;
	int arr[12] = {3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10, 2};
	// print(arr);
	// int arr[7] = {3, 4, -1, 0, 6, 2, 3};
	int t[11];
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
			if (arr[j] < arr[i])
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
	print(lis);
}
