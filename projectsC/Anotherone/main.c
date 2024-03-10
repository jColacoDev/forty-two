/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:46:11 by sinlee            #+#    #+#             */
/*   Updated: 2024/03/10 21:29:28 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve(int arr[4][4]);
int	input_to_arr(char *str, int *attr, int arr[4][4]);


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
		solve(arr);
	}
	else
		write(1, "Error", 5);
	return (0);
}