/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:58 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/03 18:57:03 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_stacks
{
	t_stack	**stack_a;
	t_stack	**stack_b;
}			t_stacks;


t_stack	*ps_dbllstnew(int data);
void	ps_dbllstadd_back(t_stack **lst, t_stack *new_node);
void	ps_dbllstclear(t_stack **lst);

void	swap(t_stack **head, char stack);


#endif
