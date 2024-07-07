/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:58 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/07 17:56:56 by mmaksimo         ###   ########.fr       */
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

t_stack	*ps_dbllstnew(int data);
void	ps_dbllstadd_back(t_stack **lst, t_stack *new_node);
void	ps_dbllstadd_front(t_stack **head, t_stack *new_node);
void	ps_dbllstclear(t_stack **lst);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);

void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);

void	rev_rotate_a(t_stack **stack_a);
void	rev_rotate_b(t_stack **stack_b);
void	rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
