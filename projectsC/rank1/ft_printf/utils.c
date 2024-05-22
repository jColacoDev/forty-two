/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:08:31 by joao-rde          #+#    #+#             */
/*   Updated: 2024/05/22 16:30:03 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_hex(char **str, char **prefix, int c, t_flags flags)
{
	int	len;

	if (flags.hash && (*str)[0] != '0')
	{
		*prefix = "0x";
		if (c == 'X')
			*prefix = "0X";
	}
	if (flags.dot && flags.precision >= 0)
	{
		len = ft_strlen(*str);
		if (len < flags.precision)
			*str = ft_strpad(*str, '0', flags.precision - len, 0);
	}
	if (flags.width > 0)
		handle_flag_width(str, *prefix, flags);
}

static int	handle_pointer_width(char *full_str, t_flags flags)
{
	int				padding_len;
	int				count;
	char			*padded_str;

	padding_len = flags.width - ft_strlen(full_str);
	padded_str = malloc(flags.width + 1);
	if (!padded_str)
	{
		free(full_str);
		return (0);
	}
	if (flags.minus)
	{
		ft_strcpy(padded_str, full_str);
		ft_memset(padded_str + ft_strlen(full_str), ' ', padding_len);
	}
	else
	{
		ft_memset(padded_str, ' ', padding_len);
		ft_strcpy(padded_str + padding_len, full_str);
	}
	padded_str[flags.width] = '\0';
	count = ft_putstr(padded_str);
	free(padded_str);
	return (count);
}

static int	handle_pointer(va_list ap, t_flags flags)
{
	int				count;
	char			*str;
	char			*full_str;
	unsigned long	ptr;

	count = 0;
	ptr = va_arg(ap, unsigned long);
	if (ptr == 0)
		full_str = ft_strdup("(nil)");
	else
	{
		str = ft_utoa_base(ptr, 16, "0123456789abcdef");
		full_str = ft_strjoin("0x", str);
		free(str);
	}
	if (flags.width > (int)ft_strlen(full_str))
		handle_pointer_width(full_str, flags);
	else
		count = ft_putstr(full_str);
	free(full_str);
	return (count);
}

static int	handle_hex_and_pointer(va_list ap, int c, t_flags flags)
{
	int		count;
	char	*str;
	char	*base;
	char	*prefix;

	prefix = "";
	if (c == 'p')
		return (handle_pointer(ap, flags));
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	str = ft_utoa_base(va_arg(ap, unsigned int), 16, base);
	handle_hex(&str, &prefix, c, flags);
	count = ft_putstr(prefix) + ft_putstr(str);
	free(str);
	return (count);
}

int	handle_number_conversion(va_list ap, int c, t_flags flags)
{
	int		count;
	char	*str;
	char	*prefix;

	prefix = "";
	count = 0;
	str = NULL;
	if (c == 'x' || c == 'X' || c == 'p')
		return (handle_hex_and_pointer(ap, c, flags));
	else if (c == 'u')
		str = ft_utoa_base(va_arg(ap, unsigned int), 10, "0123456789");
	else if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(ap, int));
		if (flags.plus && str[0] != '-')
			prefix = "+";
		else if (flags.space && str[0] != '-')
			prefix = " ";
	}
	handle_num_flags(&str, prefix, flags);
	count = ft_putstr(prefix) + ft_putstr(str);
	free(str);
	return (count);
}
