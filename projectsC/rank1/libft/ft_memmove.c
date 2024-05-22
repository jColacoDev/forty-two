/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:33:15 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/15 17:55:38 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*source;
	char		*dst;
	int			i;

	if (!dest && !src)
		return ((void *)dest);
	source = src;
	dst = dest;
	i = n;
	if (dst < source)
		ft_memcpy(dst, source, n);
	else
		while (--i >= 0)
			dst[i] = source[i];
	return (dest);
}
