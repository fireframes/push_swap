/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:37:56 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 16:15:29 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	dbllstadd_back(stack, first);
	second->prev = NULL;
	*stack = second;
}

/*	Rotate A : Shift up all elements of stack A by 1.

	The first element becomes the last one.*/
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

/*	Rotate B : Shift up all elements of stack B by 1.

	The first element becomes the last one.*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

/*	Rotate AB : ra and rb at the same time.*/
void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
