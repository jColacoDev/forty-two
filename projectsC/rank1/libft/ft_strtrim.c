/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:52:57 by joao-rde          #+#    #+#             */
/*   Updated: 2024/04/11 17:56:45 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains_trimmable(char const *set, char const c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	find_begin(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i] && contains_trimmable(set, str[i]))
		i++;
	return (i);
}

static int	find_end(char const *str, char const *set, int len)
{
	int	i;

	i = len - 1;
	while (i > 0 && contains_trimmable(set, str[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1)
		return (NULL);
	start = find_begin(s1, set);
	end = find_end(s1, set, ft_strlen(s1));
	if (end < start || (!*set && !*s1))
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
