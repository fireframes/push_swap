/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:17:55 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/28 16:56:31 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(char **input, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (input[i])
	{
		dbllstadd_back(stack_a, dbllstnew(ft_atol(input[i])));
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**input;
	t_stack	*stack_a;
	t_stack	*stack_b;

	input = parse_args(argc, argv);
	if (input == NULL)
		error_exit(input);
	if (!check_input(input))
		error_exit(input);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(input, &stack_a);
	sort_stack(&stack_a, &stack_b);
	dbllstclear(&stack_a);
	dbllstclear(&stack_b);
	if (argc == 2)
		free_split(input);
	return (0);
}
