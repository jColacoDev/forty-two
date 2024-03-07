/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:30:25 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/07 15:41:35 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int i, int j)
{
	char	buffer[5];

	buffer[0] = i / 10 + '0';
	buffer[1] = i % 10 + '0';
	buffer[2] = ' ';
	buffer[3] = j / 10 + '0';
	buffer[4] = j % 10 + '0';
	write(1, buffer, 5);
	if (!(i == 98 && j == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			if (i != j)
			{
				ft_print(i, j);
			}
			j++;
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/