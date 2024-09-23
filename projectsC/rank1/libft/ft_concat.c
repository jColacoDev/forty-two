/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:00 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 18:06:55 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat(const char *str1, const char *str2, int at_beginning)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
	{
		exit(1);
	}
	if (at_beginning)
	{
		ft_strcat(result, str2, 0);
		ft_strcat(result, str1, len2);
	}
	else
	{
		ft_strcat(result, str1, 0);
		ft_strcat(result, str2, len1);
	}
	return (result);
}
