/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:24:48 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/18 17:33:29 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	n;

	n = nb + 1;
	while (1)
	{
		if (ft_is_prime(n))
			return (n);
		n++;
	}
	return (0);
}

/*
int	main(void)
{
	int i=-5;
	while(i++<30)
	{
		printf("Next prime of %d: %d\n", i, ft_find_next_prime(i));
	}
	return (0);
}
*/
