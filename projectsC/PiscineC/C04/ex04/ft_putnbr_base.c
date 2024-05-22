/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:01:00 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/14 22:08:47 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_valid_base(const char *base)
{
	int	i;
	int	j;

	if (base == NULL || base[0] == '\0' || base[1] == '\0')
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	long_nbr;
	int			base_length;
	char		digit;

	if (!ft_is_valid_base(base))
		return ;
	long_nbr = nbr;
	if (long_nbr < 0)
	{
		ft_putchar('-');
		long_nbr = -long_nbr;
	}
	base_length = ft_strlen(base);
	if (long_nbr >= base_length)
		ft_putnbr_base(long_nbr / base_length, base);
	digit = base[long_nbr % base_length];
	ft_putchar(digit);
}

/*
int	main(void)
{
	// base binaria
	printf("Bases binarias, n = 47. \"01\" e \"\\/\"\n");
	ft_putnbr_base(47, "01");
	ft_putchar('\n');
	printf("Esperado: 101111\n");
	ft_putnbr_base(47, "\\/");
	ft_putchar('\n');
	printf("Esperado: /\\////\n");
	// base 5
	printf("Bases 5, n = 36. \"01345\" e \"sd2ek\"\n");
	ft_putnbr_base(36, "01345");
	ft_putchar('\n');
	printf("Esperado: 131\n");
	ft_putnbr_base(36, "sd2ek");
	ft_putchar('\n');
	printf("Esperado: d2d\n");
	// base 10
	printf("Bases 10, n = 0, n =
		%d. \"0123456789\" e \",.;\\][{}@#\"\n",INT_MIN);
	ft_putnbr_base(0, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(INT_MIN, "0123456789");
	ft_putchar('\n');
	printf("Esperado: -2147483648\n");
	ft_putchar('\n');
	ft_putnbr_base(INT_MIN, ",.;\\][{}@#");
	printf("Esperado: -;.]}]@\\{]@\n");
	// base 16
	printf("Bases 16,n =-65040. \"0123456789ABCDEF\" e \"jdlskmnMKZxVuzfa\"\n");
	ft_putnbr_base(-65040, "0123456789ABCDEF");
	ft_putchar('\n');
	printf("Esperado: -FE10\n");
	ft_putnbr_base(-65040, "jdlskmnMKZxVuzfa");
	ft_putchar('\n');
	printf("Esperado: -afdj\n");
	// base 0 e base 1, nao pode aparecer nada
	printf("Bases 0 e 1, nao deve aparecer nada, n = 256.\n");
	ft_putnbr_base(-29092, "0");
	ft_putnbr_base(-29092, "");
	return (0);
}
*/
