/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:52 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/07 17:56:32 by mmaksimo         ###   ########.fr       */
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

/*	pa : Take the first element at the top of B and put it at the top of A.

	Do nothing if B is empty.*/
void	push_a(t_stack **stack_a, t_stack **stack_b)
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
	ps_dbllstadd_front(stack_a, push_node);
	write(1, "pa\n", 3);
}

/*	pb : Take the first element at the top of A and put it at the top of B.

	Do nothing if A is empty.*/
void	push_b(t_stack **stack_a, t_stack **stack_b)
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
	ps_dbllstadd_front(stack_b, push_node);
	write(1, "pb\n", 3);
}

/*	ra : Shift up all elements of stack A by 1.

	The first element becomes the last one.*/
void	rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	ps_dbllstadd_back(stack_a, first);
	*stack_a = second;
	write(1, "ra\n", 3);
}

/*	rb : Shift up all elements of stack B by 1.

	The first element becomes the last one.*/
void	rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	ps_dbllstadd_back(stack_b, first);
	*stack_b = second;
	write(1, "rb\n", 3);
}

/*	rr : ra and rb at the same time.*/
void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

/*	rra : Shift down all elements of stack A by 1.

	The last element becomes the first one.*/
void	rev_rotate_a(t_stack **stack_a)
{
		t_stack *last;
		t_stack *new_last;

		if (*stack_a == NULL)
			return ;
		last = *stack_a;
		while (last->next != NULL)
			last = last->next;
		new_last = last->prev;
		new_last->next = NULL;
		ps_dbllstadd_front(stack_a, last);
		write(1, "rra\n", 4);
}

/*	rrb : Shift down all elements of stack B by 1.

	The last element becomes the first one.*/
void	rev_rotate_b(t_stack **stack_b)
{
	t_stack *last;
	t_stack *new_last;

	if (*stack_b == NULL)
		return ;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	ps_dbllstadd_front(stack_b, last);
	write(1, "rrb\n", 4);
}

/*	rrr : rra and rrb at the same time.*/
void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}
