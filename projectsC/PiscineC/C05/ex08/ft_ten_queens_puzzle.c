/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:54:27 by joao-rde          #+#    #+#             */
/*   Updated: 2024/03/21 15:39:54 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_solution(int board[][10], int board_size)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			if (board[j][i])
			{
				aux = j + '0';
				write(1, &aux, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	check_diagonals(int board[][10], int board_size, int row, int col)
{
	int	aux_col;
	int	aux_row;

	aux_row = row;
	aux_col = col;
	while (aux_row >= 0 && aux_col >= 0)
	{
		if (board[aux_row][aux_col])
			return (0);
		aux_row--;
		aux_col--;
	}
	aux_row = row;
	aux_col = col;
	while (aux_row < board_size && aux_col >= 0)
	{
		if (board[aux_row][aux_col])
			return (0);
		aux_row++;
		aux_col--;
	}
	return (1);
}

int	is_valid(int board[][10], int board_size, int row, int col)
{
	int	aux_col;
	int	aux_row;

	aux_row = 0;
	while (aux_row < row)
	{
		if (board[aux_row][col])
			return (0);
		aux_row++;
	}
	aux_col = 0;
	while (aux_col < col)
	{
		if (board[row][aux_col])
			return (0);
		aux_col++;
	}
	return (check_diagonals(board, board_size, row, col));
}

void	puzzle_algorithm(int board[][10], int col, int board_size, int *counter)
{
	int	i;

	if (col >= board_size)
	{
		print_solution(board, board_size);
		(*counter)++;
		return ;
	}
	i = 0;
	while (i < board_size)
	{
		if (is_valid(board, board_size, i, col))
		{
			board[i][col] = 1;
			puzzle_algorithm(board, col + 1, board_size, counter);
			board[i][col] = 0;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	board_size;
	int	counter;
	int	i;
	int	j;

	counter = 0;
	board_size = 10;
	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	puzzle_algorithm(board, 0, board_size, &counter);
	return (counter);
}


int	main(void)
{
	int	solutions;

	solutions = ft_ten_queens_puzzle();
	if (solutions == 724)
		printf("> OK, result: %d.\n", solutions);
	else
		printf("> KO, expected: 724, got: %d\n", solutions);
	return (0);
}

