/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:50:46 by kmatjuhi          #+#    #+#             */
/*   Updated: 2023/12/28 11:28:56 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst, char c)
{
	t_stack	*first;
	t_stack	*second;

	if (*lst == NULL || (*lst)->next == *lst)
		return ;
	printf("s%c\n", c);
	if ((*lst)->next->next == *lst)
	{
		*lst = (*lst)->next;
		return ;
	}
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	second->prev->next = second;
	*lst = second;
}

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		*src = temp->next;
		temp->prev->next = *src;
		(*src)->prev = temp->prev;
		temp->next = temp;
		temp->prev = temp;
	}
	add_front(&(*dest), temp);
	printf("p%c\n", c);
}

void	rotate(t_stack **lst, char c)
{
	if (!(*lst) || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->next;
	printf("r%c\n", c);
}

void	reverse_rotate(t_stack **lst, char c)
{
	if (!(*lst) || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->prev;
	printf("rr%c\n", c);
}
