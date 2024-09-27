/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:00 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/16 17:06:22 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_aux(char *str, int *len, int n, t_flags flags)
{
	unsigned int	num;

	num = n;
	if (n < 0)
		num = -n;
	if (n == 0 && !flags.precision)
		str[0] = ' ';
	else if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--(*len)] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_flags(int n, t_flags flags)
{
	int				len;
	char			*str;
	unsigned int	num;

	num = n;
	if (n < 0)
		num = -n;
	len = ft_count_digits_base(num, 10);
	if (n == 0)
		len = 1;
	else if (n < 0)
		len += 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_itoa_aux(str, &len, n, flags);
	return (str);
}
