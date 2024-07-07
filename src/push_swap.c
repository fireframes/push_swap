/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/07 17:41:02 by mmaksimo         ###   ########.fr       */
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
	t_stack *stack_b;


	stack_a	= NULL;
	stack_b	= NULL; //ps_dbllstnew(42);
	// ps_dbllstadd_back(&stack_b, ps_dbllstnew(21));

	int	i;

	i = 1;
	while (i < argc)
	{
		ps_dbllstadd_back(&stack_a, ps_dbllstnew(ft_atoi(*(argv + i))));
		i++;
	}
	// ft_printf("head data: %d\n", stack_a->data);

	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);


	// swap_a(&stack_a);
	// swap_b(&stack_b);
	// swap_ss(&stack_a, &stack_b);
	
	// rev_rotate_a(&stack_a);
	// rotate_a(&stack_a);
	// swap_ss(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);
	// push_a(&stack_a, &stack_b);

	// rev_rotate_b(&stack_a);
	// rotate_b(&stack_a);
	// swap_ss(&stack_a, &stack_b);

	// rev_rotate_rrr(&stack_a, &stack_b);

	// rotate_rr(&stack_a, &stack_b);

	if (stack_a)
		ft_printf("head a: %d\n", stack_a->data);
	else
		ft_printf("head a: (null)\n");

	if (stack_b)
		ft_printf("head b: %d\n", stack_b->data);
	else
		ft_printf("head b: (null)\n");
	
	ft_printf("\u2014\t\u2014\n\n");


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
			ft_printf("%d", demo_b->data);
			demo_b = demo_b->next;
		}
		else
			ft_printf(" \t");
		ft_printf("\n");
	}
	ft_printf("\u2014\t\u2014\n");

	ft_printf("a\tb\n");

	// ft_printf("head data: %d\n", stack_b->data);

	ps_dbllstclear(&stack_a);
	ps_dbllstclear(&stack_b);

	return 0;
}
