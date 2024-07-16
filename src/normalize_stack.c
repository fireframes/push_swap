/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:02:25 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 22:38:58 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack(t_stack **stack)
{
	int	*input;
	int	*copy;

	t_stack *node;
	node = *stack;

	input = stack_to_array(stack); //copy the stack into input array...
									//reminder : there is no duplicate

	copy = copy_input_array(input); // copy the numbers from input

	sort_copy();

	// set input nums to corresponding positions of sorted copy
	for(int i = 0 ; i < input.size() ; ++i)
    	for(int j = 0 ; j < copy.size() ; ++j)
        	if (input[i] == copy[j])
			{
            	input[i] = j;
            	break ;
        	}

	// put input into stack a ...
	int i = 0;
	while (node)
	{
		node->idx = input[i];
		node = node->next;
		i++;
	}
/*
Remark : This is actually not the most efficient way to implement them. If you want a more efficient program, please learn about binary search or unordered_map (hash)
*/
}
