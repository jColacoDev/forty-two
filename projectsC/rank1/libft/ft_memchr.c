/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:31:05 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/11 17:55:52 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	size_t				i;

	mem = s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
