/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:32:51 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/16 16:55:38 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strpad(char *str, char pad, int len, int left_align)
{
	int		orig_len;
	char	*new_str;
	int		i;

	orig_len = ft_strlen(str);
	new_str = malloc(len + orig_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	if (left_align)
	{
		ft_strcpy(new_str, str);
		while (i < len)
			new_str[orig_len + i++] = pad;
	}
	else
	{
		while (i < len)
			new_str[i++] = pad;
		ft_strcpy(new_str + i, str);
	}
	new_str[orig_len + len] = '\0';
	free(str);
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;
	
	if (!dst || !src)
		return (NULL); 
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
