/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dbllst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:59:41 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/05 22:14:24 by mmaksimo         ###   ########.fr       */
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
}

void	ps_dbllstadd_front(t_stack **head, t_stack *new_node)
{
	t_stack *old_node;

	old_node = *head;
	new_node->next = old_node;
	new_node->prev = NULL;
	old_node->prev = new_node;
	*head = new_node;
}

// MAYBE TAKE THIS PART FROM push_a FUNCTION?

// void	ps_dbllstdel_head(t_stack **head)
// {
// 	t_stack	*old_head;
// 	t_stack	*new_head;

// 	old_head = *head;
// 	if (old_head == NULL)
// 		return ;
// 	new_head = old_head->next;
// 	new_head->prev = NULL;
// 	*head = new_head;
// 	free(old_head);
// 	old_head = NULL;
// }



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
