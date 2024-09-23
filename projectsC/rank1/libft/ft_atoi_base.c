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

static int	ft_get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
		{
			sign = -1;
		}
		(*str)++;
	}
	return (sign);
}

static int	ft_get_value(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	result;
	int	sign;
	int	base_len;
	int	value;

	result = 0;
	base_len = ft_strlen(base);
	while (ft_isspace(*str))
	{
		str++;
	}
	sign = ft_get_sign(&str);
	while (*str)
	{
		value = ft_get_value(*str, base);
		if (value == -1)
			break ;
		result = result * base_len + value;
		str++;
	}
	return (sign * result);
}
