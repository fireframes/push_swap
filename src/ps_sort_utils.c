/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:23:12 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 16:14:29 by mmaksimo         ###   ########.fr       */
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

void	sort_three(t_stack **stack_a)
{
	t_stack	*max;
	t_stack	*head;

	head = *stack_a;
	max = dbllstget_max(stack_a);
	if (max == head)
		ra(stack_a);
	else if (max == head->next)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	else
		swap_a(stack_a);
}
