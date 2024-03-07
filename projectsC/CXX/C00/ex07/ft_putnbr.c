/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:30:46 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/07 19:34:54 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	buffer[20];
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (nb > 0)
	{
		buffer[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i-- > 0)
	{
		write(1, &buffer[i], 1);
	}
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	write(1,"\n",1);
	ft_putnbr(2147483647);
	write(1,"\n",1);
	ft_putnbr(2147);
	write(1,"\n",1);
	ft_putnbr(-21647);
	return (0);
}
*/