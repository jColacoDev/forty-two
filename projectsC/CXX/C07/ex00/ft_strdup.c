/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:23:33 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/20 17:31:42 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*start;

	start = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (start);
}

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;

	length = ft_strlen(src) + 1;
	copy = (char *)malloc(length);
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, src);
	return (copy);
}

/*
int	main(void)
{
	char	*str;
	char	*str_copy;

	str = "Test string.";
	str_copy = ft_strdup(str);
	if (strcmp(str, str_copy) != 0)
		printf("KO, string is not the same.\n");
	else
		printf("OK.\n");
	str = "";
	str_copy = ft_strdup(str);
	if (strcmp(str, str_copy) != 0)
		printf("KO, string is not the same.\n");
	else
		printf("OK.\n");
	str = "eeeeeeee vida de gado";
	str_copy = ft_strdup(str);
	if (strcmp(str, str_copy) != 0)
		printf("KO, string is not the same.\n");
	else
		printf("OK.\n");
	return (0);
}
*/
