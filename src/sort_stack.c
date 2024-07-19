/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/20 01:33:39 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	all_ones(t_stack *head, int bit_pos)
{
	t_stack	*node;

	node = head;
	while (node)
	{
		if ((node->idx >> bit_pos & 1) == 0)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	radix_sort(t_stack **stack_a, t_stack **stack_b, uint32_t size)
{
	int	i;
	int	max_num;
	int	max_pos;

	max_num = size - 1;
	max_pos = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		max_pos++;
	}
	i = 0;

	// need optimization
	// if 3 left? sort three? 
	while (i < max_pos || !is_sorted(stack_a))
	{
		while (!all_ones(*stack_a, i))
		{
			if ((*stack_a)->idx >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b != NULL)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, uint32_t size_a)
{

	if (!*stack_a || !*stack_a)
		return ; // exit w error!

	// size_a = dbllst_size(stack_a);
	normalize_stack(stack_a, size_a);
	radix_sort(stack_a, stack_b, size_a);
	

}



