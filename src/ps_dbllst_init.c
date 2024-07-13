/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dbllst_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:59:41 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/12 21:59:36 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_dbllstnew(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ps_dbllstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp_node;

	tmp_node = *head;
	if (tmp_node == NULL)
	{
		*head = new_node;
		return ;
	}
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	new_node->prev = tmp_node;
	new_node->next = NULL;
}

void	ps_dbllstadd_front(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp_node;

	tmp_node = *head;
	if (tmp_node == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	new_node->next = tmp_node;
	new_node->prev = NULL;
	tmp_node->prev = new_node;
	*head = new_node;
}

void	ps_dbllstclear(t_stack **head)
{
	t_stack	*node;

	node = *head;
	if (node == NULL)
		return ;
	ps_dbllstclear(&(node->next));
	free(node);
	*head = NULL;
}
