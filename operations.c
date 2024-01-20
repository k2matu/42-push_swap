/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:50:46 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 14:42:44 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_second(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

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

void	swap(t_stack **a_lst, t_stack **b_lst, char c)
{
	if (c == 'a' || c == 's')
	{
		if (!(*a_lst) || (*a_lst)->next == *a_lst)
			return ;
		swap_second(a_lst);
	}
	if (c == 'b' || c == 's')
	{
		if (!(*b_lst) || (*b_lst)->next == *b_lst)
			return ;
		swap_second(b_lst);
	}
	ft_printf("s%c\n", c);
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
	ft_printf("p%c\n", c);
}

void	rotate(t_stack **a_lst, t_stack **b_lst, char c)
{
	if (c == 'a' || c == 'r')
	{
		if (!(*a_lst) || (*a_lst)->next == *a_lst)
			return ;
		*a_lst = (*a_lst)->next;
	}
	if (c == 'b' || c == 'r')
	{
		if (!(*b_lst) || (*b_lst)->next == *b_lst)
			return ;
		*b_lst = (*b_lst)->next;
	}
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack **a_lst, t_stack **b_lst, char c)
{
	if (c == 'a' || c == 'r')
	{
		if (!(*a_lst) || (*a_lst)->next == *a_lst)
			return ;
		*a_lst = (*a_lst)->prev;
	}
	if (c == 'b' || c == 'r')
	{
		if (!(*b_lst) || (*b_lst)->next == *b_lst)
			return ;
		*b_lst = (*b_lst)->prev;
	}
	ft_printf("rr%c\n", c);
}
