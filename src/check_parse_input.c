/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 02:28:34 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/28 03:45:37 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(int argc, char **argv)
{
	char	**input;
	int		elem;

	input = NULL;
	elem = 0;
	if (argc < 2)
	{
		ft_printf("No arguments provided\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (input == NULL)
			return (NULL);
	}
	else
	{
		while (argv[1][elem])
			if (argv[1][elem++] == ' ')
				return (NULL);
		input = &argv[1];
	}
	return (input);
}

int	check_input(char **input)
{
	int			i;
	int			j;
	int			count;
	long int	convert_i;

	i = 0;
	while (input[i])
	{
		convert_i = ft_atol(input[i]);
		if ((convert_i == 0 && !(check_zero(input[i]) == 1))
			|| (convert_i < INT_MIN || convert_i > INT_MAX))
			return (0);
		j = 0;
		count = 0;
		while (input[j])
		{
			if (ft_atol(input[j]) == convert_i)
				count++;
			j++;
		}
		if (count != 1)
			return (0);
		i++;
	}
	return (1);
}
