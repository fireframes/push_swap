/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:52 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/05 22:25:08 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	Swap the first 2 elements at the top of stack a.
	#	Do nothing if there is only one or no elements.*/
void	swap_a(t_stack **stack_a)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = *stack_a;
	/* return if there is only 1 or 0 nodes -- can check in earlier calls*/
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

void	swap_b(t_stack **stack_b)
{
	t_stack	*node1;
	t_stack	*node2;


	node1 = *stack_b;
	/* return if there is only 1 or 0 nodes -- can check in earlier calls*/
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

/*	sa and sb at the same time */
void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

/*	Take the first element at the top of B and put it at the top of A.
	#	Do nothing if B is empty.*/
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *push_node;
	t_stack *new_head_b;

	if (*stack_b == NULL)
		return ;
	push_node = *stack_b;
	new_head_b = push_node->next;
	new_head_b->prev = NULL;
	*stack_b = new_head_b;
	ps_dbllstadd_front(stack_a, push_node);
}

/*	Take the first element at the top of A and put it at the top of B.
	#	Do nothing if A is empty.*/
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *push_node;
	t_stack *new_head_a;

	if (*stack_a == NULL)
		return ;
	push_node = *stack_a;
	new_head_a = push_node->next;
	new_head_a->prev = NULL;
	*stack_a = new_head_a;
	ps_dbllstadd_front(stack_b, push_node);
}



