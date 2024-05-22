/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:30:08 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/20 22:08:47 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	total_length;
	int	i;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += (size - 1) * ft_strlen(sep);
	return (total_length);
}

void	concat_strings(int size, char **strs, char *sep, char *result)
{
	int	malloc_index;
	int	sep_len;
	int	i;

	malloc_index = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		ft_strcpy(result + malloc_index, strs[i]);
		malloc_index += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(result + malloc_index, sep);
			malloc_index += sep_len;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_length;

	if (size <= 0)
	{
		result = (char *)malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		*result = '\0';
		return (result);
	}
	total_length = calculate_total_length(size, strs, sep);
	result = (char *)malloc((total_length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	concat_strings(size, strs, sep, result);
	result[total_length] = '\0';
	return (result);
}

/*
int	main(void)
{
	int		offset;
	char	**strs;
	char	*res_str;

	strs = malloc(3 * sizeof(char *));
	if (strs == NULL)
		return (1);
	offset = 0;
	while (offset < 3)
	{
		strs[offset] = "abc";
		offset++;
	}
	res_str = ft_strjoin(3, strs, ", ");
	if (res_str == NULL)
		return (1);
	printf("res: %s\n", res_str);
	free(strs);
	free(res_str);
	return (0);
}
*/
