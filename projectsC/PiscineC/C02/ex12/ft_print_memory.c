/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:08:53 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/12 20:28:40 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	print_hex_address(unsigned long int addr)
{
	int				i;
	unsigned char	nibble;

	i = 15 / 2;
	while (i >= 0)
	{
		nibble = (addr >> (i * 4)) & 0xF;
		print_hex(nibble);
		i--;
	}
	write(1, ": ", 2);
}

void	print_char(unsigned char c)
{
	if (c >= 32 && c <= 126)
	{
		write(1, &c, 1);
	}
	else
	{
		write(1, ".", 1);
	}
}

void	print_memory_line(unsigned char *ptr, unsigned int size)
{
	unsigned int	j;
	char			str[16];

	j = -1;
	while (++j < 16)
	{
		str[j] = '.';
		if (ptr[j] >= 32 && ptr[j] <= 126)
		{
			str[j] = ptr[j];
		}
		if (j < size)
		{
			print_hex(ptr[j]);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (j % 2 == 1)
		{
			write(1, " ", 1);
		}
	}
	write(1, str, 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex_address((unsigned long int)ptr);
		print_memory_line(ptr, size - i);
		i += 16;
		ptr += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

/*
int	main(void)
{
	char	*str;

	str = "Bonjour les aminches\n\b\rc  est fou\ntout\rce qu on peut faire avec\r\r\
	nprint_memory\n\n\r\blol\rlol\r \b";
	ft_print_memory(str, strlen(str));
	return (0);
}

*/
