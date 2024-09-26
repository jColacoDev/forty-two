/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:52:54 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 20:18:37 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tri(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		run_op(SA, a, NULL);
	else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		run_op(SA, a, NULL);
		run_op(RRA, a, NULL);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		run_op(RA, a, NULL);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		run_op(SA, a, NULL);
		run_op(RA, a, NULL);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		run_op(RRA, a, NULL);
}

static void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b)
		to_move = min(a);
	smart_rotate_a(a, to_move);
	run_op(PA, a, b);
}

static void	sort_tri_complex(t_stack *a, t_stack *b)
{
	run_ops(PB, a, b, a->top - 2);
	sort_tri(a);
	while (b->top >= 0)
		put_top_in_position(a, b);
	smart_rotate_a(a, 0);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		run_op(SA, a, NULL);
	else if (a->top == 2)
		sort_tri(a);
	else
		sort_tri_complex(a, b);
}
