/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:47:55 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 08:39:29 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **a, t_stack **b, int moves, char c)
{
	while (moves != 0 && moves > 0)
	{
		rotate(&*a, &*b, c);
		moves--;
	}
	while (moves != 0 && moves < 0)
	{
		reverse_rotate(&*a, &*b, c);
		moves++;
	}
}

static int	calculate_moves(int a_moves, int b_moves)
{
	int	moves;

	if (a_moves > b_moves && a_moves >= 0 && b_moves >= 0)
		moves = b_moves;
	else if (a_moves < b_moves && a_moves >= 0 && b_moves >= 0)
		moves = a_moves;
	else if (a_moves < b_moves && a_moves < 0 && b_moves < 0)
		moves = b_moves;
	else
		moves = a_moves;
	return (moves);
}

void	push_back(t_stack **a, t_stack **b, int pos)
{
	int	a_moves;
	int	b_moves;
	int	moves;

	a_moves = count_a_moves(a, pos);
	b_moves = count_b_moves(b, pos);
	moves = calculate_moves(a_moves, b_moves);
	while (0 > moves && a_moves >= 0 && b_moves >= 0)
	{
		rotate(&*a, &*b, 'r');
		a_moves -= 1;
		b_moves -= 1;
		moves++;
	}
	while (0 > moves && a_moves < 0 && b_moves < 0)
	{
		reverse_rotate(&*a, &*b, 'r');
		a_moves += 1;
		b_moves += 1;
		moves++;
	}
	rotate_stack(&(*a), &(*b), a_moves, 'a');
	rotate_stack(&(*a), &(*b), b_moves, 'b');
	push(&*b, &*a, 'a');
}
