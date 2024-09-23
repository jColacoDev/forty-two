/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:29:00 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 18:07:25 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char c, int width)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)malloc(sizeof(char) * (width + 1));
	if (!str)
		return (NULL);
	while (++i < width)
		str[i] = c;
	str[width] = '\0';
	return (str);
}
