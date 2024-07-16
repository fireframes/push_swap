/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:28:51 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 21:28:11 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	current_index(t_stack **stack)
// {
// 	int		i;
// 	int		median;
// 	t_stack	*node;

// 	if (!*stack)
// 		return ;
// 	node = *stack;
// 	i = 0;
// 	median = dbllst_len(stack) / 2;
// 	while (node)
// 	{
// 		node->idx = i;
// 		if (i <= median)
// 			node->above_median = 1;
// 		else
// 			node->above_median = 0;
// 		i++;
// 		node = node->next;
// 	}
// }

void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	/*every a node needs a target of closest by value b node*/

	while (node)
	{

	}

}



analize_cost(stack_a, stack_b);
set_cheapest(stack_a);
