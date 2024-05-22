/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:24:09 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/14 22:06:19 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_char_to_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	base_len;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	base_len = 0;
	if (!str || !base || !ft_is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && ft_char_to_digit(str[i], base) != -1)
		result = result * base_len + ft_char_to_digit(str[i++], base);
	return (result * sign);
}

/*
int	main(void)
{
	char	base1[] = "01";
	char	base2[] = "01234567";
	char	base3[] = "0123456789ABCDEF";
	char	base4[] = "0123456789ABCDEF";
	int		result1;
	int		result2;
	int		result3;
	int		result4;
	int		result5;
	int		result6;

	char test_str1[] = "1010"; // base is binary
	result1 = ft_atoi_base(test_str1, base1);
	printf("String '%s' converted to integer in base '%s': %d\n", test_str1,
		base1, result1);
	char test_str2[] = "123"; // base is octal
	result2 = ft_atoi_base(test_str2, base2);
	printf("String '%s' converted to integer in base '%s': %d\n", test_str2,
		base2, result2);
	char test_str3[] = "FF"; // base is hexadecimal
	result3 = ft_atoi_base(test_str3, base3);
	printf("String '%s' converted to integer in base '%s': %d\n", test_str3,
		base3, result3);
	char test_str4[] = "7AB"; // base is hexadecimal
	result4 = ft_atoi_base(test_str4, base4);
	printf("String '%s' converted to integer in base '%s': %d\n", test_str4,
		base4, result4);
	char test_str5[] = "11"; // base is binary
	result5 = ft_atoi_base(test_str5, base1);
	printf("String '%s' converted to integer in base '%s': %d\n", test_str5,
		base1, result5);
	char test_str6[] = "1010101"; // base is binary
	result6 = ft_atoi_base(test_str6, base1);
	printf("String '%s' converted to integer in base '%s': %d\n", test_str6,
		base1, result6);
	result6 = ft_atoi_base("0", "0123456789");
	printf("String '%s' converted to integer in base '%s': %d\n", "0",
		"0123456789", result6);
	return (0);
}
*/
