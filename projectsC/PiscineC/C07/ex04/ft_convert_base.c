/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:26:59 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/21 22:02:18 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_isspace(char c);
int		ft_strlen(char *str);
int		ft_char_to_digit(char c, char *base);
int		digits_n(int value, int base_len);
int		get_sign(char *str, int *index);

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

int	calculate_value(char *str, char *base, int *index)
{
	int	value;
	int	digit;
	int	base_len;

	value = 0;
	base_len = ft_strlen(base);
	while (str[*index])
	{
		digit = ft_char_to_digit(str[*index], base);
		if (digit == -1)
			return (0);
		value = value * base_len + digit;
		(*index)++;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	value;
	int	index;

	index = 0;
	if (!str || !base || !ft_is_valid_base(base))
		return (0);
	while (ft_isspace(str[index]))
		index++;
	sign = get_sign(str, &index);
	value = calculate_value(str, base, &index);
	return (value * sign);
}

char	*ft_itoa_base(int value, char *base)
{
	int		aux_value;
	int		digits;
	char	*str;

	aux_value = value;
	digits = digits_n(aux_value, ft_strlen(base));
	str = (char *)malloc(sizeof(char) * (digits + 1));
	str[digits] = '\0';
	if (aux_value < 0)
		str[0] = '-';
	else if (aux_value == 0)
		str[0] = base[0];
	while (aux_value)
	{
		aux_value = aux_value % ft_strlen(base);
		if (aux_value < 0)
			aux_value *= -1;
		str[--digits] = base[aux_value];
		aux_value /= ft_strlen(base);
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value;
	char	*result;

	value = ft_atoi_base(nbr, base_from);
	if (value == 0 || value == -1)
		return (NULL);
	result = ft_itoa_base(value, base_to);
	if (result == NULL)
		return (NULL);
	return (result);
}
/*
int	main(void)
{
	char	nbr[] = "10";
	char	base_to[] = "0123456789ABCDEF";
	char	base_from[] = "0123456789";
	char	*res;

	res = ft_convert_base(nbr, base_from, base_to);
	if (res == NULL)
	{
		printf("Conversion failed\n");
		return (1);
	}
	printf("Original number: %s\n", nbr);
	printf("Base from: %s\n", base_from);
	printf("Base to: %s\n", base_to);
	printf("Converted number: %s\n", res);
	return (0);
}
*/
