/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dbllst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:08:38 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/13 15:23:46 by mmaksimo         ###   ########.fr       */
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

t_stack	*ps_dbllstget_max(t_stack **head)
{
	t_stack	*max;
	t_stack	*node;

	if (*head == NULL)
		return (NULL);
	node = *head;
	max = node;
	while (node->next != NULL)
	{
		node = node->next;
		if (node->data > max->data)
			max = node;
	}
	return (max);
}
