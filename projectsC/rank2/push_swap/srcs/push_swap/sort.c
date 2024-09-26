/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:08:50 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 20:18:41 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack)
{
	t_stack	*new;

	if (is_sorted(stack) || stack->top <= 0)
		return ;
	new = initialize(stack->size);
	if (stack->top < SORT_COMPLEX_LIMIT)
		sort_small(stack, new);
	else
		sort_complex(stack, new);
	free_stack(new);
}
