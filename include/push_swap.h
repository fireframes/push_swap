/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:58 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/16 21:40:36 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				data;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*dbllstnew(int data);
t_stack	*dbllstget_last(t_stack **head);
t_stack	*dbllstget_max(t_stack **head);

int		dbllst_len(t_stack **head);

void	dbllstadd_back(t_stack **lst, t_stack *new_node);
void	dbllstadd_front(t_stack **head, t_stack *new_node);
void	dbllstclear(t_stack **lst);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);

void	rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		is_sorted(t_stack **head);
void	sort_three(t_stack **stack_a);

#endif
