/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:48:05 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/18 17:03:13 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
int	main(void)
{
	int	res;
	int	index;

	index = 0;
	while (index < 12)
	{
		res = ft_fibonacci(index);
		printf("%d, ", res);
		index++;
	}
	res = ft_fibonacci(index);
	printf("%d\n", res);
	return (0);
}
*/
