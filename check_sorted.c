/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:21:35 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/16 21:05:36 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack **a)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = *a;
	while (temp->data < temp->next->data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
