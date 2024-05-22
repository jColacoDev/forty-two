/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:51:40 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/11 17:56:48 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_size;
	char	*result;

	substr_size = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		substr_size = ft_strlen(s + start);
	result = (char *)malloc(sizeof(char) * (substr_size + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, substr_size + 1);
	return (result);
}
