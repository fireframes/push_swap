/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/24 01:41:27 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*max;
	t_stack	*head;

	head = *stack_a;
	max = dbllstget_max(stack_a);
	if (head == max)
		ra(stack_a);
	else if (head->next == max)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	else
		sa(stack_a);
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	int		nodes_to_push;
	int		i;

	nodes_to_push = size_a - 3;
	i = 0;
	while (i < nodes_to_push)
	{
		init_idx(stack_a);
		move_min_to_push(stack_a, size_a);
		pb(stack_a, stack_b);
		size_a--;
		i++;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	j;
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
	while (i < max_pos)
	{
		int all_sorted = 1;
		j = 0;
		while (j < size)
		{
			if ((*stack_a)->idx >> i & 1)
				ra(stack_a);
			else
			{
				pb(stack_a, stack_b);
				all_sorted = 0;
			}
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		if (all_sorted && is_sorted(stack_a))
			break;
		i++;
	}
}
