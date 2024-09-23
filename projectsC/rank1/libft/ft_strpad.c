/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:33:42 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/16 16:38:20 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
