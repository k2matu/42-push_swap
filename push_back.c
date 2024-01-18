/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:47:55 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/18 18:47:14 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back(t_stack **a, t_stack **b, int pos)
{
	int	a_moves;
	int	b_moves;
	int	moves;
	int i;

	i = 0;
	a_moves = count_a_moves(a, pos);
	b_moves = count_b_moves(b, pos);
	if (a_moves >= 0 && b_moves >= 0)
	{
		if (a_moves > b_moves)
			moves = b_moves;
		else
			moves = a_moves;
		while (i < moves)
		{
			rotate(&*a, &*b, 'r');
			a_moves -= 1;
			b_moves -= 1;
			i++;
		}
	}
	else if (a_moves < 0 && b_moves < 0)
	{
		if (a_moves < b_moves)
			moves = b_moves;
		else
			moves = a_moves;
		while (i > moves)
		{
			reverse_rotate(&*a, &*b, 'r');
			a_moves -= 1;
			b_moves -= 1;
			moves++;
		}
	}
	while (a_moves != 0)
	{
		if (a_moves > 0)
		{
			rotate(&*a, &*b, 'a');
			a_moves--;
		}
		else
		{
			reverse_rotate(&*a, &*b, 'a');
			a_moves++;
		}
	}
	while (b_moves != 0)
	{
		if (b_moves > 0)
		{
			rotate(&*a, &*b, 'b');
			b_moves--;
		}
		else
		{
			reverse_rotate(&*a, &*b, 'b');
			b_moves++;
		}
	}
	if (a_moves == 0 && b_moves == 0)
		push(&*b, &*a, 'a');
}