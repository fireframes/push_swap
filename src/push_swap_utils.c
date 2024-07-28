/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 02:24:39 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/28 16:57:56 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char **split)
{
	if (split)
		free_split(split);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			split[i] = NULL;
			i++;
		}
		free(split);
		split = NULL;
	}
}

int	check_zero(char *nptr)
{
	if (*nptr == '0')
	{
		if (*(nptr + 1) == '\0')
			return (1);
		else
			return (-1);
	}
	return (0);
}

long int	ft_atol(const char *nptr)
{
	long int		num;
	int				neg;
	unsigned int	i;

	num = 0;
	neg = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = (num + (nptr[i] - '0')) * 10;
		i++;
	}
	if (!ft_isdigit(nptr[i]) && nptr[i])
		return (0);
	num /= 10;
	return (num * neg);
}
