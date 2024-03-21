/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:55:38 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/12 19:09:50 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str1[] = "abcdefghi";
	char	str2[] = "AbcDefGhI";
	char	str3[] = "ABCDEFGHI";

	printf("str1: %s\n", str1);
	ft_strlowcase(str1);
	printf("str1_low: %s\n", str1);
	printf("str2: %s\n", str2);
	ft_strlowcase(str2);
	printf("str2_low: %s\n", str2);
	printf("str3: %s\n", str3);
	ft_strlowcase(str3);
	printf("str3_low: %s\n", str3);
	return (0);
}
*/
