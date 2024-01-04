/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:02:45 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/28 11:39:51 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_new(long data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = new;
	new->prev = new;
	return (new);
}

void	add_front(t_stack **lst, t_stack *new)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	tail = (*lst)->prev;
	new->next = head;
	new->prev = tail;
	tail->next = new;
	head->prev = new;
	*lst = new;
}

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*head;
	t_stack	*tail;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	tail = (*lst)->prev;
	new->next = head;
	new->prev = tail;
	tail->next = new;
	head->prev = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while ((*stack)->next != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = temp;
	}
}

int	count_nodes(t_stack *stack)
{
	t_stack	*temp;
	int		count;

	count = 1;
	temp = stack;
	stack = stack->next;
	while (temp != stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
