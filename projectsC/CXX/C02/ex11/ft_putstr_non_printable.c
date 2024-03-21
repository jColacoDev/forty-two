/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:28:44 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/12 20:27:14 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	hex1;
	char	hex2;

	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			ft_putchar('\\');
			if (*str / 16 < 10)
				hex1 = (*str / 16) + '0';
			else
				hex1 = (*str / 16) - 10 + 'a';
			if (*str % 16 < 10)
				hex2 = (*str % 16) + '0';
			else
				hex2 = (*str % 16) - 10 + 'a';
			ft_putchar(hex1);
			ft_putchar(hex2);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}
}

/*
int	main(void)
{
	char	str[] = {'0', '1', 2, 30, 16, '4', 'a', 19, 'C'};

	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}
*/
