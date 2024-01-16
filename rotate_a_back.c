/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:31:02 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/12 15:31:42 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_back(t_stack **a, int count, int min)
{
	int		i;
	t_stack	*temp;
	t_stack	*b;

	b = NULL;
	i = 0;
	temp = (*a);
	while (temp->data != min)
	{
		i++;
		temp = temp->next;
	}
	while ((*a)->data != min)
	{
		if (i < count / 2)
			rotate(&(*a), &b, 'a');
		else
			reverse_rotate(&(*a), &b, 'a');
	}
}