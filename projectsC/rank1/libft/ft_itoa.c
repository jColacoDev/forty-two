/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:53:54 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/12 18:20:53 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_n(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	natural_itoa(long nb, char *str)
{
	if (nb >= 10)
		natural_itoa(nb / 10, str - 1);
	*str = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		is_negative;
	long	nb;

	nb = n;
	is_negative = nb < 0;
	if (is_negative)
		nb = -nb;
	len = digits_n(nb) + is_negative;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (is_negative)
		*result = '-';
	natural_itoa(nb, result + len - 1);
	result[len] = '\0';
	return (result);
}
