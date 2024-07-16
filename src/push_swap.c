/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 21:36:13 by mmaksimo         ###   ########.fr       */
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


	int	size_a;
	size_a = dbllst_len(&stack_a);

	if (size_a > 1 && !is_sorted(&stack_a))
	{
		if (size_a == 2)
			swap_a(&stack_a);
		else if (size_a == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
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
			ft_printf("%d", demo_b->data);
			demo_b = demo_b->next;
		}
		else
			ft_printf(" \t");
		ft_printf("\n");
	}
	ft_printf("\u2014\t\u2014\n");

	ft_printf("a\tb\n");

	if (stack_a)
		ft_printf("head a: %d\n", stack_a->data);
	else
		ft_printf("head a: (null)\n");

	if (stack_b)
		ft_printf("head b: %d\n", stack_b->data);
	else
		ft_printf("head b: (null)\n");

	// ft_printf("\nstack A count: %d\n", dbllst_len(&stack_a));
	// ft_printf("stack B count: %d\n", dbllst_len(&stack_b));

	// t_stack *last_node_a = dbllstget_last(&stack_a);
	// t_stack *last_node_b = dbllstget_last(&stack_b);

	// ft_printf("\nstack A last: %d\n", last_node_a->data);
	// ft_printf("stack B last: %d\n", last_node_b->data);

	// rotate_rr(&stack_a, &stack_b);

	// last_node_a = dbllstget_last(&stack_a);
	// last_node_b = dbllstget_last(&stack_b);

	// ft_printf("\nstack A last: %d\n", last_node_a->data);
	// ft_printf("stack B last: %d\n", last_node_b->data);


	// if (ps_dbllst_issorted(&stack_a))
	// 	printf("\nstack_a is sorted\n");
	// else
	// 	printf("\nstack_a is not sorted\n");

	// if (ps_dbllst_issorted(&stack_b))
	// 	printf("\nstack_b is sorted\n");
	// else
	// 	printf("\nstack_b is not sorted\n");

	// t_stack *max_a;
	// t_stack *max_b;

	// max_a = dbllstget_max(&stack_a);
	// max_b = dbllstget_max(&stack_b);

	// ft_printf("\nstack A max: %d\n", max_a->data);
	// ft_printf("stack B max: %d\n", max_b->data);

	dbllstclear(&stack_a);
	dbllstclear(&stack_b);

	return 0;
}
