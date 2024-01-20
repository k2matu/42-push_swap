/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:32:30 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/20 19:51:38 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

statiic void	reverse_stack(t_stack **a, int count)
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

static void	sort_small(t_stack **a, t_stack **b, int count)
{
	if (count < 3)
	{
		swap(&(*a), &(*b), 'a');
		return ;
	}
	if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->prev->data)
		swap(&(*a), &(*b), 'a');
	else if ((*a)->data > (*a)->next->data \
	&& (*a)->next->data < (*a)->prev->data)
		rotate(&(*a), &(*b), 'a');
	else if ((*a)->data > (*a)->next->data)
	{
		swap(&(*a), &(*b), 'a');
		reverse_rotate(&(*a), &(*b), 'a');
	}
	else if ((*a)->data > (*a)->prev->data)
		reverse_rotate(&(*a), &(*b), 'a');
	else if ((*a)->next->data > (*a)->prev->data)
	{
		swap(&(*a), &(*b), 'a');
		rotate(&(*a), &(*b), 'a');
	}
	return ;
}

static void	sort_big_scnd(t_stack **a, int *arr, int count)
{
	t_stack	*b;
	int		*lis;
	int		min_pos;

	b = NULL;
	if (count < 6)
	{
		if (count == 5)
			push(&(*a), &b, 'b');
		push(&(*a), &b, 'b');
		sort_small(&(*a), &b, count);
	}
	else
	{
		lis = get_lis(arr, count);
		push_to_stack_b(lis, &(*a), &b, count);
		free(lis);
	}
	while (b)
	{
		min_pos = cheapest_number(&(*a), &b);
		push_back(&(*a), &b, min_pos);
	}
	reverse_stack(&*a, count_nodes(*a));
}

static void	sort_big(t_stack **a, int count)
{
	int		*arr;
	int		*xtra;

	arr = lst_to_arr(a, count);
	quicksort(arr, 0, count - 1);
	fill_stack_pos(&(*a), arr, count);
	free(arr);
	xtra = lst_to_arr(a, count);
	sort_big_scnd(&(*a), xtra, count);
	free(xtra);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	b = NULL;
	if (argc < 2)
		return (0);
	a = stoi(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	count = count_nodes(a);
	if (check_sorted(&a) == count)
	{
		free_stack(&a);
		return (0);
	}
	else if (count <= 3)
		sort_small(&a, &b, count);
	else
		sort_big(&a, count);
	free_stack(&a);
	return (0);
}
