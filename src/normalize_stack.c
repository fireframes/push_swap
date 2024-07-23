/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:02:25 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/23 22:57:30 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack **stack, int size)
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

static int	*copy_array(int *array, int size)
{
	int	*copy;
	int	i;

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

static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int			tmp;

	i = 0;
	tmp = array[i];
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
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

static void	normalize_input(int *input, int *copy, int size)
{
	int	i;
	int	j;

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

void	normalize_stack(t_stack **stack, int size)
{
	t_stack		*node;
	int			*input;
	int			*copy;
	int			i;

	input = stack_to_array(stack, size);
	if (!input)
		return ;
	copy = copy_array(input, size);
	if (!copy)
		return ;
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
	free(input);
	free(copy);
}

// raise error after bad allocation?
//reminder : there is no duplicates!
// set ptrs to NULL after freeing?
/*
Remark : This is actually not the most efficient way
to implement them. If you want a more efficient program, 
please learn about binary search or unordered_map (hash)
*/
