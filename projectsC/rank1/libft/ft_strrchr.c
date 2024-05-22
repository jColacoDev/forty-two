/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:37:59 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/15 18:32:57 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s + ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)ptr);
	while (ptr-- > s)
		if (*ptr == (char)c)
			return ((char *)ptr);
	return (NULL);
}
