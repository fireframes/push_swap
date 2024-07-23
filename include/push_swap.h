/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:58 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/07/24 01:26:23 by mmaksimo         ###   ########.fr       */
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

t_stack		*dbllstnew(int data);
t_stack		*dbllstget_last(t_stack **head);
t_stack		*dbllstget_max(t_stack **head);

uint32_t	dbllst_size(t_stack **head);

void		dbllstadd_back(t_stack **lst, t_stack *new_node);
void		dbllstadd_front(t_stack **head, t_stack *new_node);
void		dbllstclear(t_stack **lst);

void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

int			is_sorted(t_stack **head);
void		init_idx(t_stack **stack_a);
t_stack		*get_min_node(t_stack **stack_a);
void		move_min_to_push(t_stack **stack_a, int size_a);

void		sort_three(t_stack **stack_a);
void		sort_four_five(t_stack **stack_a, t_stack **stack_b, int size_a);
void		normalize_stack(t_stack **stack, int size);
void		radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

#endif
