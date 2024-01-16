/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:43:24 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/16 20:49:04 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_check(t_stack *stack, char *str, long n)
{
	t_stack	*temp;

	if (n < -2147483648 || n > 2147483647)
		return (-1);
	if (n == 0 && ft_strncmp(str, "0", ft_strlen(str)) != 0)
		return (-1);
	if (!stack)
		return (0);
	temp = stack;
	if (stack->data == n)
		return (-1);
	stack = stack->next;
	while (temp != stack)
	{
		if (stack->data == n)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

void	free_arr(char **value)
{
	int i;

	i = 0;
	while (value[i])
		free(value[i++]);
	free(value);
}

static t_stack	*get_numbers(char **value, int i)
{
	t_stack	*head;
	t_stack	*new;
	int		j;

	head = NULL;
	j = i;
	while (value[i])
	{
		new = add_new(ft_atol(value[i]));
		if (error_check(head, value[i], new->data) == -1)
		{
			free(new);
			if (head)
				free_stack(&head);
			head = NULL;
			break ;
		}
		i++;
		add_back(&head, new);
	}
	if (j == 0)
		free_arr(value);
	return (head);
}

t_stack	*stoi(int argc, char **argv)
{
	char	**a;

	a = NULL;
	if (argc == 2)
	{
		a = ft_split(argv[1], ' ');
		return (get_numbers(a, 0));
	}
	else
		return (get_numbers(argv, 1));
}
