/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:42:54 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/19 12:59:38 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_number(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		moves;
	int		min_moves;
	int		min_pos;
	int		count;

	count = count_nodes(*b);
	min_moves = 600;
	temp = *b;
	while (count--)
	{
		moves = count_moves(a, b, temp->pos);
		if (moves < min_moves)
		{
			min_moves = moves;
			min_pos = temp->pos;
			if (min_moves < 2)
				return (min_pos);
		}
		temp = temp->next;
	}
	return (min_pos);
}
