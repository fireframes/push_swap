/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:37:56 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/12 00:35:36 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
