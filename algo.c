/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:31:21 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/08 10:51:01 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_stack **a)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = *a;
	while (temp->data < temp->next->data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	algo(t_stack **a)
{
	int	count;

	count = count_nodes(*a);
	if (check(a) == count)
		return ;
	if (count < 3)
		swap(&(*a), 'a');
	else if (count == 3)
		sort_three(&(*a));
	else if (count < 6)
		sort_five(&(*a), count);
	else
		sort_big(&(*a), count);
}
