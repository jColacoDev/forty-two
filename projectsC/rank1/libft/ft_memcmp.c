/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:20:43 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/15 18:03:37 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	int					size;

	size = n;
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (*p1 == *p2 && --size > 0)
	{
		p1++;
		p2++;
	}
	if (size == 0)
		return (0);
	return (*p1 - *p2);
}
