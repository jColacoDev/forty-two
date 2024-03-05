/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:22 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/05 02:52:22 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z' )
	{
		write(1, &c, 1);
		c++;
	}
}

int	main(void)
{
	print_alphabet();
	return (0);
}