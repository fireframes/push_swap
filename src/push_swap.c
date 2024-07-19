/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/20 01:18:36 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a	= NULL;
	stack_b	= NULL;

	if (argc < 2)
	{
		ft_printf("No arguments provided\n");
		exit(EXIT_FAILURE);
	}

	/*Parse and check stack*/
	int	i;

	i = 1;
	while (i < argc)
	{
		dbllstadd_back(&stack_a, dbllstnew(ft_atoi(*(argv + i))));
		i++;
	}

	ft_printf("\u2014\t\u2014\n\n");


	uint32_t	size_a;
	size_a = dbllst_size(&stack_a);

	if (size_a > 1 && !is_sorted(&stack_a))
	{
		if (size_a == 2)
			sa(&stack_a);
		else if (size_a == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b, size_a);
	}


	ft_printf("\u2014\t\u2014\n");


	// Print lists
	t_stack *demo_a = stack_a;
	t_stack *demo_b = stack_b;

	while (demo_a || demo_b)
	{
		if (demo_a != NULL)
		{
			ft_printf("%d\t", demo_a->data);
			demo_a = demo_a->next;
		}
		else
			ft_printf(" \t");
		if (demo_b != NULL)
		{
			ft_printf("\t%d", demo_b->idx);
			demo_b = demo_b->next;
		}
		else
			ft_printf(" \t");
		ft_printf("\n");
	}
	ft_printf("\u2014\t\u2014\n");

	ft_printf("a\tb\n");

	// if (stack_a)
	// 	ft_printf("head a: %d\n", stack_a->data);
	// else
	// 	ft_printf("head a: (null)\n");

	// if (stack_b)
	// 	ft_printf("head b: %d\n", stack_b->data);
	// else
	// 	ft_printf("head b: (null)\n");



	dbllstclear(&stack_a);
	dbllstclear(&stack_b);

	return 0;
}
