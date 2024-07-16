/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 21:40:11 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = dbllst_len(stack_a);
	if (size_a-- > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (size_a-- > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	while (size_a-- > 3 && !is_sorted(stack_a))
	{

	}
	while(*stack_b)
	{

	}

}

