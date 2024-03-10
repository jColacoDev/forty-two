/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:17:10 by sinlee            #+#    #+#             */
/*   Updated: 2024/03/10 20:02:02 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_criteria(int arr[4][4])
{
	int		i;
	int		j;
	char	ans;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
		{
			ans = arr[i][j] + 48;
			write(1, &ans, 1);
			write(1, " ", 1);
		}
		ans = arr[i][j] + 48;
		write(1, &ans, 1);
		write(1, "\n", 1);
	}
}