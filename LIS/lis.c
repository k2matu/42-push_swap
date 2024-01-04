/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:48:12 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/02 14:17:35 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int arr[11] = {3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10};
	int i = -1;
	int j = 0;
	int k = 0;
	int len = 0;
	int t[11];
	int r[11];

	while (i++ < 10)
		r[i] = -1;

	t[0] = arr[i];
	i++;

	while (i < 11)
	{
		if (arr[i] > t[len])
		{
			t[i] = arr[i];
			r[i] = t[len];
			len++;
		}
		else if (arr[i] < t[j])
			t[j] = arr[i];
		else
		{
			while (arr[i] > t[j])
				k++;
			t[k] = arr[i];
			k = 0;
		}
		i++;
	}

	i = -1;
	while (i++ < 10)
		printf("value %d is = %d\n", i, r[i]);
}
