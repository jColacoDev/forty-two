/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_smart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 22:40:51 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 20:42:58 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/push_swap.h"

int	closest_above(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->array[i] > n && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}

int	closest_below(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n < min(a))
		return (n);
	i = 0;
	k = min(a);
	while (i <= a->top)
	{
		if (a->array[i] < n && a->array[i] > k)
			k = a->array[i];
		i++;
	}
	return (k);
}

void	smart_rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		run_ops(RRA, a, NULL, find + 1);
	else
		run_ops(RA, a, NULL, a->top - find);
}

void	smart_rotate_b(t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (b->array[find] != n && find >= 0)
		find--;
	if (find < 0)
		return ;
	else if (find < b->top / 2)
		run_ops(RRB, NULL, b, find + 1);
	else
		run_ops(RB, NULL, b, b->top - find);
}
