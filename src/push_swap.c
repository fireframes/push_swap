/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/05 22:25:23 by mmaksimo         ###   ########.fr       */
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
	stack_b	= ps_dbllstnew(42);
	ps_dbllstadd_back(&stack_b, ps_dbllstnew(21));

	int	i;

	i = 1;
	while (i < argc)
	{
		ps_dbllstadd_back(&stack_a, ps_dbllstnew(ft_atoi(*(argv + i))));
		i++;
	}
	// ft_printf("head data: %d\n", stack_a->data);
	// swap_a(&stack_a);
	// swap_b(&stack_b);
	// swap_ss(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);

	ft_printf("--\n");

	// Print lists
	t_stack *demo_a = stack_a;
	while (demo_a != NULL)
	{
		ft_printf("%d\n", demo_a->data);

		demo_a = demo_a->next;
	}
	ft_printf("_\na\n");
	ft_printf("\nb:\n\n");

	t_stack *demo_b = stack_b;
	while (demo_b != NULL)
	{
		ft_printf("%d\n", demo_b->data);

		demo_b = demo_b->next;
	}
	ft_printf("head data: %d\n", stack_b->data);



	ft_printf("--\n");ft_printf("--\n");
	push_b(&stack_a, &stack_b);


	// Print lists after push_b
	t_stack *demo2_a = stack_a;
	while (demo2_a != NULL)
	{
		ft_printf("%d\n", demo2_a->data);

		demo2_a = demo2_a->next;
	}
	ft_printf("_\na\n");
	ft_printf("\nb:\n\n");

	t_stack *demo2_b = stack_b;
	while (demo2_b != NULL)
	{
		ft_printf("%d\n", demo2_b->data);

		demo2_b = demo2_b->next;
	}
	ft_printf("head data: %d\n", stack_b->data);

	ps_dbllstclear(&stack_a);
	ps_dbllstclear(&stack_b);

	return 0;
}
