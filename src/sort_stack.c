/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:58:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/18 22:27:57 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a)//, t_stack **stack_b)
{
	uint32_t	size_a;


	if (!*stack_a || !*stack_a)
		return ; // exit w error!

	size_a = dbllst_size(stack_a);

	normalize_stack(stack_a, size_a);

	// radix_sort(stack_a, stack_b);


	// while (*stack_b != NULL)
	// {
	// 	pa(stack_a, stack_b);
	// }

}

