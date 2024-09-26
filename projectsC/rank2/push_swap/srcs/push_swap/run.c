/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:29:06 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 20:01:34 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, PA))
		push(b, a);
	else if (ft_streq(op, PB))
		push(a, b);
	else if (ft_streq(op, SA))
		swap(a);
	else if (ft_streq(op, SB))
		swap(b);
	else if (ft_streq(op, RA))
		rotate(a);
	else if (ft_streq(op, RB))
		rotate(b);
	else if (ft_streq(op, RRA))
		reverse_rotate(a);
	else if (ft_streq(op, RRB))
		reverse_rotate(b);
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	run_n(char *op, t_stack *a, t_stack *b, int n)
{
	if (n <= 0)
		return ;
	run(op, a, b);
	run_n(op, a, b, n - 1);
}