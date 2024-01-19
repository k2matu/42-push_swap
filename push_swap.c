/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:32:30 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/19 04:05:56 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack **a)
{
	t_stack	*b;
	int		count;

	b = NULL;
	count = count_nodes(*a);
	if (check_sorted(a) == count)
		return ;
	if (count < 3)
		swap(&(*a), &b, 'a');
	else if (count == 3)
		sort_three(&(*a));
	else
		sort_big(&(*a), count);
		
	// if (check_sorted(a) == count)
	// 	printf("sorted");
	// printf("%d", check_sorted(a));
	// print(*a);
}

void	rotate_a_back(t_stack **a, int count)
{
	t_stack	*temp;
	t_stack	*b;
	int		i;

	b = NULL;
	i = 0;
	temp = (*a);
	while (temp->pos != 0)
	{
		i++;
		temp = temp->next;
	}
	while ((*a)->pos != 0)
	{
		if (i < count / 2)
			rotate(&(*a), &b, 'a');
		else
			reverse_rotate(&(*a), &b, 'a');
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = stoi(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	algo(&a);
	free_stack(&a);
	return (0);
}
