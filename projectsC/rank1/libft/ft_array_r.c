/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:00 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 16:40:42 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_swap(int *a, int *b)
{
	int	aux;

	aux = *b;
	*b = *a;
	*a = aux;
}

void    ft_array_r(int *array, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		_swap(&array[i++], &array[size - 1]);
		ft_array_r(array, size - 1);
	}
	i = 0;
}