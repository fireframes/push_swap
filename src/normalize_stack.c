/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:02:25 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/18 22:59:59 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	*stack_to_array(t_stack **stack, uint32_t size)
{
	t_stack		*node;
	int			*array;
	int			i;
	
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	node = *stack;
	i = 0;
	while (node)
	{
		array[i] = node->data;
		node = node->next;
		i++;
	}
	return (array);
}

static int	*copy_array(int *array, uint32_t size)
{
	int			*copy;
	uint32_t	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}
	return (copy);
}

static void	bubble_sort(int *array, uint32_t size)
{
	uint32_t	i;
	uint32_t	j;
	int			tmp;

	i = 0;
	tmp = array[i];
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if(array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_input(int *input, int *copy, uint32_t size)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (input[i] == copy[j])
			{
				input[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack **stack, uint32_t size)
{
	t_stack		*node;
	int			*input;
	int			*copy;
	int			i;

	input = stack_to_array(stack, size); //reminder : there is no duplicate!
	if (!input)
		return ; // raise error!
	copy = copy_array(input, size); // copy the numbers from input
	if (!copy)
		return ; // raise error?
	bubble_sort(copy, size);
	normalize_input(input, copy, size);
	node = *stack;
	i = 0;
	while (node)
	{
		node->idx = input[i];
		node = node->next;
		i++;
	}
	// free_array(input);
	// free_array(copy);
}

//set input nums to corresponding positions of sorted copy
	
/*
Remark : This is actually not the most efficient way to implement them. If you want a more efficient program, please learn about binary search or unordered_map (hash)
*/