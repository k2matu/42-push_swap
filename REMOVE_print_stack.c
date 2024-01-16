/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:27:29 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/12 15:27:38 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (temp == NULL)
	{
		printf("empty stack\n");
		return ;
	}
	printf("[%d] = %ld\n", stack->pos, stack->data);
	stack = stack->next;
	while (temp != stack)
	{
		printf("[%d] = %ld\n", stack->pos, stack->data);
		stack = stack->next;
	}
	printf("\n");
}