/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:38:29 by joao-rde          #+#    #+#             */
/*   Updated: 2024/06/20 14:49:23 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zero_precision(char **str, unsigned long value, t_flags flags)
{
	char	*temp;

	if (flags.dot && flags.precision == 0 && value == 0)
	{
		temp = ft_strdup("");
		if (!temp)
			return ;
		free(*str);
		*str = temp;
	}
}

static void	check_if_hex(char *str, int *is_hex)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_strchr("0123456789abcdefABCDEF", str[i]))
		{
			*is_hex = 0;
			break ;
		}
		i++;
	}
}

static void	apply_precision(char **str, t_flags flags)
{
	int	len;

	if (flags.dot && flags.precision > 0)
	{
		len = ft_strlen(*str);
		if (len < flags.precision)
			*str = ft_strpad(*str, '0', flags.precision - len, 0);
	}
}

static void	check_flag_hash(char **str, char **prefix, int c, t_flags flags)
{
	if (flags.hash && **str != '0' && **str != '\0')
	{
		*prefix = "0x";
		if (c == 'X')
			*prefix = "0X";
	}
}

void	handle_hex(char **str, char **prefix, int c, t_flags flags)
{
	unsigned long	value;
	int				is_hex;
	char			*new_str;

	if (!*str)
		return ;
	value = 0;
	is_hex = 1;
	check_if_hex(*str, &is_hex);
	if (!is_hex)
	{
		value = ft_atoi_base(*str, "0123456789abcdef");
		handle_zero_precision(str, value, flags);
	}
	check_flag_hash(str, prefix, c, flags);
	apply_precision(str, flags);
	new_str = ft_strjoin(*prefix, *str);
	free(*str);
	*str = new_str;
	if (flags.width > 0)
		handle_flag_width(str, flags);
}
