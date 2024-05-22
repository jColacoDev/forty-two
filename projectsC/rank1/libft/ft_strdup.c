/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:23:33 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/11 18:09:13 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*copy;

	length = ft_strlen(s) + 1;
	copy = (char *)malloc(length);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s, length);
	return (copy);
}
