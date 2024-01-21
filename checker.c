/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:46:39 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/21 12:03:17 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	handle_error(char *line, t_stack *a, t_stack *b)
{

	free(line);
	free_stack(&a);
	free_stack(&b);
	write(2, "Error\n", 7);
	exit(-1);
}

static void	execute_cmd(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_bonus(&(*a), &(*b), 'a');
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_bonus(&(*a), &(*b), 'b');
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_bonus(&(*a), &(*b), 's');
	else if (ft_strcmp(line, "pa\n") == 0)
		push_bonus(&(*b), &(*a), 'a');
	else if (ft_strcmp(line, "pb\n") == 0)
		push_bonus(&(*a), &(*b), 'b');
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate_bonus(&(*a), &(*b), 'a');
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate_bonus(&(*a), &(*b), 'b');
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_bonus(&(*a), &(*b), 'r');
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_bonus(&(*a), &(*b), 'a');
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_bonus(&(*a), &(*b), 'b');
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_bonus(&(*a), &(*b), 'r');
	else
		handle_error(line, *a, *b);
}

static void is_sorted(t_stack *a, t_stack *b, int count)
{
	if (check_sorted(&a) == count && !b)
	{
		ft_printf("OK\n");
		free_stack(&a);
	}
	else
	{
		free_stack(&a);
		free_stack(&b);
		ft_printf("KO\n");
	}
}

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
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
	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		execute_cmd(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	is_sorted(a, b, count);
	return (0);
}
