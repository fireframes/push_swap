/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:36:32 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 21:40:59 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Push A : Take the first element at the top of B and put it at the top of A.

	Do nothing if B is empty.*/
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*push_node;
	t_stack	*new_head_b;

	if (*stack_b == NULL)
		return ;
	push_node = *stack_b;
	if (push_node->next != NULL)
	{
		new_head_b = push_node->next;
		new_head_b->prev = NULL;
		*stack_b = new_head_b;
	}
	else
		*stack_b = NULL;
	dbllstadd_front(stack_a, push_node);
	write(1, "pa\n", 3);
}

/*	Push B : Take the first element at the top of A and put it at the top of B.

	Do nothing if A is empty.*/
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*push_node;
	t_stack	*new_head_a;

	if (*stack_a == NULL)
		return ;
	push_node = *stack_a;
	if (push_node->next != NULL)
	{
		new_head_a = push_node->next;
		new_head_a->prev = NULL;
		*stack_a = new_head_a;
	}
	else
		*stack_a = NULL;
	dbllstadd_front(stack_b, push_node);
	write(1, "pb\n", 3);
}
