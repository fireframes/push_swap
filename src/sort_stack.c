/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/28 04:20:47 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(int stack_size)
{
	int	max_pos;
	int	max_num;

	max_pos = 0;
	max_num = stack_size - 1;
	while (max_num > 0)
	{
		max_num >>= 1;
		max_pos++;
	}
	return (max_pos);
}

static void	sort_three(t_stack **stack_a)
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

static void	sort_four_five(t_stack **stack_a, t_stack **stack_b, int size_a)
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

static void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_pos;
	int	i;
	int	j;

	max_pos = get_max_pos(size);
	i = 0;
	while (i < max_pos)
	{
		j = 0;
		while (j < size)
		{
			if ((*stack_a)->idx >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		if (is_sorted(stack_a))
			break ;
		i++;
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	uint32_t	size_a;

	size_a = dbllst_size(stack_a);
	if (size_a > 1 && !is_sorted(stack_a))
	{
		if (size_a == 2)
			sa(stack_a);
		else if (size_a == 3)
			sort_three(stack_a);
		else if (size_a == 4 || size_a == 5)
			sort_four_five(stack_a, stack_b, size_a);
		else
		{
			normalize_stack(stack_a, size_a);
			radix_sort(stack_a, stack_b, size_a);
		}
	}
}
