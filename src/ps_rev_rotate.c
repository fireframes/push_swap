/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:39:11 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/12 02:09:04 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	rra : Shift down all elements of stack A by 1.

	The last element becomes the first one.*/
void	rev_rotate_a(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*stack_a == NULL)
		return ;
	last = *stack_a;
	while (last->next != NULL)
	{
		before_last = last;
		last = before_last->next;
	}
	ps_dbllstadd_front(stack_a, last);
	before_last->next = NULL;
	write(1, "rra\n", 4);
}

/*	rrb : Shift down all elements of stack B by 1.

	The last element becomes the first one.*/
void	rev_rotate_b(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack_b)
		return ;
	last = *stack_b;
	while (last->next != NULL)
	{
		before_last = last;
		last = before_last->next;
	}
	ps_dbllstadd_front(stack_b, last);
	before_last->next = NULL;
	write(1, "rrb\n", 4);
}

/*	rrr : rra and rrb at the same time.*/
void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}
