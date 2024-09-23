/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:00 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 18:07:37 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strtoul_base_aux(unsigned long *result, int i, const char *str,
		const char *base)
{
	int	j;
	int	base_len;

	base_len = ft_strlen(base);
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (!base[j])
			break ;
		*result = *result * base_len + j;
		i++;
	}
}

unsigned long	ft_strtoul_base(const char *str, const char *base)
{
	unsigned long	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		if ((str[i] == '-'))
			sign = -1;
		i++;
	}
	ft_strtoul_base_aux(&result, i, str, base);
	return (sign * result);
}
