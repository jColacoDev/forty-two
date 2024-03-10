
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:56:35 by sinlee            #+#    #+#             */
/*   Updated: 2024/03/10 20:02:28 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	puzzle_algorithm(int arr[4][4]);
int		input_to_arr(char *str, int *attr, int arr[4][4]);

int	main(int argc, char **argv)
{
	int	i;
	int	arr[4][4];
	int	attr[3];

	if (argc == 2)
	{
		i = -1;
		while (i++ < 3)
			attr[i] = 0;

		arr[3][3] = -1;
		if (input_to_arr(argv[1], attr, arr) == 1)
			return (0);
		if (arr[3][3] == -1)
			write(1, "Error", 5);
		if (arr[3][3] == -1)
			return (0);
		puzzle_algorithm(arr);
	}
	else
		write(1, "Error", 5);
	return (0);
}