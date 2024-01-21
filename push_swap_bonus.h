/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:32:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/21 08:08:44 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"

typedef struct s_stack
{
	long			data ;
	int				pos ;
	struct s_stack	*prev ;
	struct s_stack	*next ;
}	t_stack;


t_stack		*stoi(int argc, char **argv);
void		free_stack(t_stack **stack);
void		push_bonus(t_stack **src, t_stack **dest, char c);
void		reverse_rotate_bonus(t_stack **a_lst, t_stack **b_lst, char c);
void		rotate_bonus(t_stack **a_lst, t_stack **b_lst, char c);
void		swap_bonus(t_stack **a_lst, t_stack **b_lst, char c);
int			check_sorted(t_stack **a);
int			count_nodes(t_stack *stack);
void	print(t_stack *stack);

#endif