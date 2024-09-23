/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:32:22 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/16 17:12:17 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits_base(unsigned long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_utoa_base(unsigned long long n, int base, char *charset, t_flags flags)
{
	int		len;
	char	*str;

	if (base < 2)
		return (NULL);
	len = ft_count_digits_base(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0 && !flags.precision)
		str[0] = ' ';
	else if (n == 0)
		str[0] = charset[0];
	while (n > 0)
	{
		str[--len] = charset[n % base];
		n /= base;
	}
	return (str);
}
