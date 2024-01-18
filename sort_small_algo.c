/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:11:14 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/18 19:06:36 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->prev->data)
		swap(&(*a), &b, 'a');
	else if ((*a)->data > (*a)->next->data \
	&& (*a)->next->data < (*a)->prev->data)
		rotate(&(*a), &b, 'a');
	else if ((*a)->data > (*a)->next->data)
	{
		swap(&(*a), &b, 'a');
		reverse_rotate(&(*a), &b, 'a');
	}
	else if ((*a)->data > (*a)->prev->data)
		reverse_rotate(&(*a), &b, 'a');
	else if ((*a)->next->data > (*a)->prev->data)
	{
		swap(&(*a), &b, 'a');
		rotate(&(*a), &b, 'a');
	}
	return ;
}
