/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:00:09 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/20 23:36:14 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset && *charset != c)
		charset++;
	return (*charset == c);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (count);
}

char	**allocate_and_copy_substring(int w_i, char **res, char *s, char *end)
{
	char	**temp;
	char	*copy;
	char	*dest;
	int		i;

	i = -1;
	temp = (char **)malloc((w_i + 2) * sizeof(char *));
	if (!temp)
		return (NULL);
	if (res)
		while (res[i++])
			temp[i] = res[i];
	copy = (char *)malloc(((end - s) + 1) * sizeof(char));
	dest = copy;
	while (s < end)
		*dest++ = *s++;
	*dest = '\0';
	temp[w_i++] = copy;
	temp[w_i] = NULL;
	return (temp);
}

char	**ft_split(char *str, char *charset)
{
	int		word_i;
	char	**res;
	char	*end;
	char	*start;

	word_i = 0;
	res = NULL;
	while (*str != '\0')
	{
		if (!is_separator(*str, charset))
		{
			start = str;
			while (*str != '\0' && !is_separator(*str, charset))
				str++;
			end = str;
			res = allocate_and_copy_substring(word_i, res, start, end);
			if (!res)
				return (NULL);
			word_i++;
		}
		else
			str++;
	}
	return (res);
}

/*
void	print_str_array(char **arr)
{
	if (arr == NULL)
	{
		printf("Array is NULL\n");
		return ;
	}
	printf("[");
	for (int i = 0; arr[i] != NULL; i++)
	{
		printf("\"%s\"", arr[i]);
		if (arr[i + 1] != NULL)
			printf(", ");
	}
	printf("]\n");
}

int	main(void)
{
	char	*str1;
	char	*charset1;
	char	**result1;
	char	*str2;
	char	*charset2;
	char	**result2;
	char	*str3;
	char	*charset3;
	char	**result3;

	// Test 1: Splitting a string with a single separator
	str1 = "hello/world";
	charset1 = "/";
	printf("Test 1:\nInput string: \"%s\"\nSeparator: \"%s\"\nResult: ", str1,
		charset1);
	result1 = ft_split(str1, charset1);
	print_str_array(result1);
	for (int i = 0; result1[i] != NULL; i++)
		free(result1[i]);
	free(result1);
	// Test 2: Splitting a string with multiple separators
	str2 = "apple,banana,orange";
	charset2 = ",";
	printf("\nTest 2:\nInput string: \"%s\"\nSeparator: \"%s\"\nResult: ", str2,
		charset2);
	result2 = ft_split(str2, charset2);
	print_str_array(result2);
	for (int i = 0; result2[i] != NULL; i++)
		free(result2[i]);
	free(result2);
	// Test 3: Splitting a string with no separators
	str3 = "hello";
	charset3 = ",";
	printf("\nTest 3:\nInput string: \"%s\"\nSeparator: \"%s\"\nResult: ", str3,
		charset3);
	result3 = ft_split(str3, charset3);
	print_str_array(result3);
	for (int i = 0; result3[i] != NULL; i++)
		free(result3[i]);
	free(result3);
	return (0);
}
*/
