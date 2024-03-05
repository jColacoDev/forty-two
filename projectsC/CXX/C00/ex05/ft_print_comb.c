/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 03:12:46 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/05 03:12:46 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	buffer[3];
	int		i;

	i = -1;
	while (++i < 1000)
	{
		buffer[0] = i / 100 + '0';
		buffer[1] = i / 10 % 10 + '0';
		buffer[2] = i % 10 + '0';
		if (buffer[0] < buffer[1] && buffer[1] < buffer[2])
		{
			write(1, buffer, 3);
			if (i < 789)
				write(1, ", ", 2);
		}
	}
	write(1, "\n", 1);
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
