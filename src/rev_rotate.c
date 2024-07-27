/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:39:11 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/17 18:24:55 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	last = dbllstget_last(stack);
	before_last = last->prev;
	tmp = last;
	before_last->next = NULL;
	dbllstadd_front(stack, tmp);
}

/*	Reverse Rotate A : Shift down all elements of stack A by 1.

	The last element becomes the first one.*/
void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

/*	Reverse Rotate B : Shift down all elements of stack B by 1.

	The last element becomes the first one.*/
void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/*	Reverse Rotate AB : rra and rrb at the same time.*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
