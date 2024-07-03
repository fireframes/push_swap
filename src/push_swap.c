/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/03 19:11:07 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("No arguments provided\n");
		exit(EXIT_FAILURE);
	}

	t_stacks stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;

	int	i;

	i = 1;
	while (i < argc)
	{
		ps_dbllstadd_back(stacks.stack_a, ps_dbllstnew(ft_atoi(*(argv + i))));
		i++;
	}
	ft_printf("head data: %d\n", stacks.stack_a->data);

	swap_a(stacks.stack_a);


	swap_b(stacks.stack_b);


	// ft_printf("head data: %d\n", stacks.stack_a->data);

	// Print the list before
	t_stack *current = stacks.stack_a;
	while (current != NULL)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
	ft_printf("_\na\n");



	ps_dbllstclear(stacks.stack_a);


	return 0;

}
