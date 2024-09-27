/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:48:02 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/26 20:42:54 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/push_swap.h"

static int	*sorted_array_copy(t_stack *stack)
{
	int		*copy;
	size_t	size;

	size = stack->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, stack->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	index_stack(t_stack **stack)
{
	int	*sorted_copy;
	int	i;
	int	pos;
	int	*array;

	i = 0;
	array = ft_calloc((*stack)->top + 1, sizeof(*array));
	sorted_copy = sorted_array_copy(*stack);
	while (i <= (*stack)->top)
	{
		pos = 0;
		while (sorted_copy[pos] != (*stack)->array[i])
			pos++;
		array[i++] = pos;
	}
	ft_memcpy((*stack)->array, array, ((*stack)->top + 1) * sizeof(*array));
	free(sorted_copy);
	free(array);
}

int	_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (stack->array[i] != n && i >= 0)
		i--;
	return (i);
}
