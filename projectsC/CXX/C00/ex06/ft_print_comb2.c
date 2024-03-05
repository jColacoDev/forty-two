/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 03:47:43 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/05 03:47:43 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	buffer[5];
	int		i;
	int		j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			if (i != j)
			{
				buffer[0] = i / 10 + '0';
				buffer[1] = i % 10 + '0';
				buffer[2] = ' ';
				buffer[3] = j / 10 + '0';
				buffer[4] = j % 10 + '0';
				write(1, buffer, 5);
				if (!(i == 98 && j == 99))
				{
					write(1, ",", 1);
				}
			}
		}
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
