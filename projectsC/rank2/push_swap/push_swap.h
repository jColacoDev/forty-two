/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 19:51:50 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}		            t_node;  

void	print_stack(t_list *stack);

void sx(t_list **x);

void	sa(t_list **x);
void	sb(t_list **x);
void	ss(t_list **a, t_list **b);

void	px(t_list **x, t_list **y);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	rx(t_list **x);
void	ra(t_list **x);
void	rb(t_list **x);
void	rr(t_list **a, t_list **b);

void	rrx(t_list **x);
void	rra(t_list **x);
void	rrb(t_list **x);
void	rrr(t_list **a, t_list **b);

void	quick_sort(t_list **stack_a, t_list **stack_b);
void    insertion_sort(t_list **a, t_list **b);
void    radix_sort(t_list **a, t_list **b);

int     find_min(t_list *x);
void    rotate_to_top(int val, t_list **a);
void    sort_three_in_a(t_list **a);

#endif
