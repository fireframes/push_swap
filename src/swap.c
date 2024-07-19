/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:32:49 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/17 18:24:35 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *stack;
	if (!node1 || node1->next == NULL)
		return ;
	node2 = node1->next;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = NULL;
	*stack = node2;
}

/*	Swap A : Swap the first 2 elements at the top of stack A.
	
	Do nothing if there is only one or no elements.*/
void	sa(t_stack **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

/*	Swap B : Swap the first 2 elements at the top of stack B.
	
	Do nothing if there is only one or no elements.*/
void	sb(t_stack **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

/*	ss : sa and sb at the same time.*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
