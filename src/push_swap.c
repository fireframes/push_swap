/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/02 23:14:50 by mmaksimo         ###   ########.fr       */
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

	t_stack *stack_a;
	int i;

	stack_a = NULL;

	i = 1;
	while (i < argc)
	{
		ps_lstadd_back(&stack_a, ps_lstnew(ft_atoi(*(argv + i))));
		i++;
	}

	// Print the list
	t_stack *current = stack_a;
	while (current != NULL)
	{
		ft_printf("%d\n", current->num);
		current = current->next;
	}
	ft_printf("_\na\n");

	ps_lstclear(&stack_a);


	return 0;

}
