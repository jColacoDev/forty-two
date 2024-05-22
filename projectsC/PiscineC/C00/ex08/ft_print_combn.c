/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:30:40 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/07 15:41:23 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(int data[], int n)
{
	char	buffer[20];
	int		buffer_index;
	int		i;

	buffer_index = 0;
	i = 0;
	while (i < n)
	{
		buffer[buffer_index++] = data[i] + '0';
		i++;
	}
	write(1, buffer, buffer_index);
}

int	is_first_combination_func(int data[], int index)
{
	int	i;
	int	is_first_combination;

	is_first_combination = 1;
	i = 0;
	while (i < index)
	{
		if (data[i] != i)
		{
			is_first_combination = 0;
			break ;
		}
		i++;
	}
	return (is_first_combination);
}

void	generate_combinations(int data[], int start, int index, int n)
{
	int	i;
	int	is_first_combination;

	if (index == n)
	{
		is_first_combination = is_first_combination_func(data, n);
		if (!is_first_combination)
		{
			write(1, ", ", 2);
		}
		print_combination(data, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		data[index] = i;
		generate_combinations(data, i + 1, index + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	data[10];
	int	first;

	first = 1;
	if (n < 1 || n > 9)
	{
		return ;
	}
	generate_combinations(data, 0, 0, n);
}

/*
int	main(void)
{
	ft_print_combn(2);
	return (0);
}
*/