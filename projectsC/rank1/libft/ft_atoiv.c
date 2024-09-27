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

bool	ft_atoiv(const char *str, int *n)
{
	int		signal;
	bool	overflow;

	*n = 0;
	signal = -1;
	overflow = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = 1;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 - (*str++ - '0');
		if (*n > 0 || (*n == INT_MIN && signal < 0))
			overflow = true;
	}
	*n *= signal;
	return (overflow);
}
