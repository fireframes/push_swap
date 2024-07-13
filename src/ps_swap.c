/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:32:49 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/13 15:56:02 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	sa : Swap the first 2 elements at the top of stack A.
	
	Do nothing if there is only one or no elements.*/
void	swap_a(t_stack **stack_a)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *stack_a;
	if (!node1 || node1->next == NULL)
		return ;
	node2 = node1->next;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	*stack_a = node2;
	write(1, "sa\n", 3);
}

/*	sb : Swap the first 2 elements at the top of stack B.
	
	Do nothing if there is only one or no elements.*/
void	swap_b(t_stack **stack_b)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *stack_b;
	if (!node1 || node1->next == NULL)
		return ;
	node2 = node1->next;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	*stack_b = node2;
	write(1, "sb\n", 3);
}

/*	ss : sa and sb at the same time.*/
void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
