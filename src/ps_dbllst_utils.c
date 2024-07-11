/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dbllst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:08:38 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/12 01:41:04 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_dbllstcount(t_stack **head)
{
	t_stack	*node;
	int		count;

	if (*head == NULL)
		return (0);
	count = 1;
	node = *head;
	while (node->next != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}

t_stack	*ps_dbllstget_last(t_stack **head)
{
	t_stack	*node;
	
	node = *head;
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ps_dbllst_issorted(t_stack **head)
{
	t_stack	*node;

	node = *head;
	if (node != NULL)
	{
		while (node->next != NULL)
		{
			if (node->data > node->next->data)
				return (0);
			node = node->next;
		}
	}
	return (1);
}