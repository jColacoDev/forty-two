/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:59:04 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 18:09:07 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_length;
	size_t	source_length;

	i = 0;
	dest_length = ft_strlen(dst);
	source_length = ft_strlen(src);
	if (size < 1 || dest_length > size)
		return (source_length + size);
	while (src[i] && dest_length + i < size - 1)
	{
		dst[dest_length + i] = src[i];
		i++;
	}
	dst[dest_length + i] = '\0';
	return (dest_length + source_length);
}
