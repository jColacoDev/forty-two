/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:30:46 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/14 22:06:59 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digit;
	long	long_nb;

	long_nb = nb;
	if (long_nb < 0)
	{
		long_nb = -long_nb;
		write(1, "-", 1);
	}
	if (long_nb > 9)
		ft_putnbr(long_nb / 10);
	digit = long_nb % 10 + '0';
	write(1, &digit, 1);
}

/*
int	main(void)
{
	write(1, "-1: ", 4);
	ft_putnbr(-1);
	write(1, "\n1: ", 4);
	ft_putnbr(1);
	write(1, "\n-10: ", 6);
	ft_putnbr(-10);
	write(1, "\n10: ", 5);
	ft_putnbr(10);
	write(1, "\nINT_MAX: ", 10);
	ft_putnbr(INT_MAX);
	write(1, "\nINT_MIN: ", 10);
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
	write(1, "0: ", 4);
	ft_putnbr(0);
	return (0);
}
*/
