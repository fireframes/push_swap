/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/13 16:16:21 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = ps_dbllstcount(stack_a);
	if (size_a-- > 3 && !is_sorted(stack_a))
		push_b(stack_a, stack_b);
	if (size_a-- > 3 && !is_sorted(stack_a))
		push_b(stack_a, stack_b);
	while (size_a > 3 && !is_sorted(stack_a))
	{
		init_nodes_a();
		move_a_to_b();
		size_a--;
	}
	sort_three(stack_a);
	while(*stack_b)
	{
		init_nodes_b();
		move_b_to_a();
	}
	current_idx(*stack_a);
	min_on_top(stack_a);
}
