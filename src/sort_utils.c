/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:23:12 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/24 01:34:39 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **head)
{
	t_stack	*node;

	node = *head;
	if (node != NULL)
	{
		while (node->next != NULL)
		{
			if (node->data > node->next->data)
				return (0);
			node = node->next;
		}
	}
	return (1);
}

void	init_idx(t_stack **stack_a)
{
	t_stack	*node;
	int 	i;
	
	node = *stack_a;
	i = 0;
	while (node)
	{
		node->idx = i;
		node = node->next;
		i++;
	}
}

t_stack *get_min_node(t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*min_node;
	
	node = *stack_a;
	min_node = node;
	while (node)
	{
		if (node->data < min_node->data)
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

void	move_min_to_push(t_stack **stack_a, int size_a)
{
	t_stack	*min_node;
	int		position;
	int		median;

	min_node = get_min_node(stack_a);
	position = min_node->idx;
	median = size_a / 2;
	if (position > median)
	{
		while (position < size_a)
		{
			rra(stack_a);
			position++;
		}
	}
	else
		while (position)
		{
			ra(stack_a);
			position--;
		}
}
