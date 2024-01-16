/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:31:21 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/15 11:38:09 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack **a)
{
	int	count;

	count = count_nodes(*a);
	if (check_sorted(a) == count)
		return ;
	if (count < 3)
		swap(&(*a), 'a');
	else if (count == 3)
		sort_three(&(*a));
	else if (count < 6)
		sort_five(&(*a), count);
	else
		sort_big(&(*a), count);
	// print(*a);
}
