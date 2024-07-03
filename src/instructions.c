/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:52 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/03 19:00:20 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *stack_a;
	node2 = node1->next;
	/* return if there is only 1 or 2 nodes -- can check in earlier calls*/
	if (node1->next == NULL || node2->next == NULL)
		return ;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	*stack_a = node2;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *stack_b;
	node2 = node1->next;
	/* return if there is only 1 or 2 nodes -- can check in earlier calls*/
	if (node1->next == NULL || node2->next == NULL)
		return ;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	*stack_b = node2;
	write(1, "sb\n", 3);
}

void	swap_ss(t_stacks *stacks)
{
	swap_a(stacks->stack_a);
	swap_b(stacks->stack_b);
}
