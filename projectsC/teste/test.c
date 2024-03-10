
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

void	inc_asign(int grid[4][4], int constant, int roworcolumn, int inc_or_dec)
{
	int	z;

	if (inc_or_dec == 0)
	{
		z = -1;
		while (++z < 4)
		{
			if (roworcolumn == 0)
				grid[constant][z] = z + 1;
			else
				grid[z][constant] = z + 1;
		}
	}
	else
	{
		z = 4;
		while (--z > -1)
		{
			if (roworcolumn == 0)
				grid[constant][z] = 4 - z;
			else
				grid[z][constant] = 4 - z;
		}
	}
}

void	asign_one(int grid[4][4], int i, int j)
{
	if (i == 0)
		grid[0][j] = 4;
	else if (i == 1)
		grid[3][j] = 4;
	else if (i == 2)
		grid[j][0] = 4;
	else
		grid[j][3] = 4;
}

void	asign(int grid[4][4], int *i, int *j, int arr[4][4])
{
	int	z;

	z = -1;
	if (arr[*i][*j] == 1)
		asign_one(grid, *i, *j);
	else if (*i == 0)
		inc_asign(grid, *j, 1, 0);
	else if (*i == 1)
		inc_asign(grid, *j, 1, 1);
	else if (*i == 2)
		inc_asign(grid, *j, 0, 0);
	else
		inc_asign(grid, *j, 0, 1);
}

void	init_grid(int arr[4][4], int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == 4 || arr[i][j] == 1)
			{
				asign(grid, &i, &j, arr);
			}
		}
	}
}
/////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////

void	solve(int arr[4][4]);
void	print_criteria(int arr[4][4]);
void	init_grid(int arr[4][4], int grid[4][4]);
int		recursion(int grid[4][4], int arr[4][4], int r, int c);
int		row_leftright(int check, int *attr, int grid[4][4], int arr[4][4]);
int		col_updown(int check, int *attr, int grid[4][4], int arr[4][4]);
int		rightleft(int check, int *attr, int grid[4][4], int arr[4][4]);
int		downup(int check, int *attr, int grid[4][4], int arr[4][4]);

int	is_valid(int grid[4][4], int arr[4][4], int *attr)
{
	grid[attr[0]][attr[1]] = attr[2];
	if (row_leftright(0, attr, grid, arr) == 1)
		return (1);
	if (col_updown(0, attr, grid, arr) == 1)
		return (1);
	if (rightleft(0, attr, grid, arr) == 1)
		return (1);
	if (downup(0, attr, grid, arr) == 1)
		return (1);
	return (0);
}

int	condition(int arr[4][4], int r, int c)
{
	if ((r == 0) && (arr[0][c] == 2 || arr[0][c] == 3))
		return (1);
	if ((r == 3) && (arr[1][c] == 2 || arr[1][c] == 3))
		return (1);
	if ((c == 0) && (arr[2][r] == 2 || arr[2][r] == 3))
		return (1);
	if ((c == 3) && (arr[3][r] == 2 || arr[3][r] == 3))
		return (1);
	return (0);
}

int	condition_loop(int *i, int *attr, int arr[4][4], int grid[4][4])
{
	int	r;
	int	c;

	r = attr[0];
	c = attr[1];
	while (++*i < 5)
	{
		if (*i == 4 && (attr[0] == 0 || attr[1] == 0 \
			|| attr[0] == 3 || attr[1] == 3))
		{
			if (condition(arr, r, c) == 1)
				continue ;
		}
		attr[2] = *i;
		if (is_valid(grid, arr, attr) == 0)
		{
			if (recursion(grid, arr, r, c + 1) == 0)
				return (0);
			grid[r][c] = -1;
		}
		else
			grid[r][c] = -1;
	}
	return (1);
}

int	recursion(int grid[4][4], int arr[4][4], int r, int c)
{
	int	i;
	int	attr[3];

	i = 0;
	attr[0] = r;
	attr[1] = c;
	if (r == 4)
		return (0);
	else if (c == 4)
		return (recursion(grid, arr, r + 1, 0));
	else if (grid[r][c] != -1)
		return (recursion(grid, arr, r, c + 1));
	else
	{
		if (condition_loop(&i, attr, arr, grid) == 0)
			return (0);
		else
			return (1);
	}
}

void	solve(int arr[4][4])
{
	int	grid[4][4];
	int	i;
	int	j;
	int	ans;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			grid[i][j] = -1;
	}
	init_grid(arr, grid);
	ans = recursion(grid, arr, 0, 0);
	if (ans == 0)
		print_criteria(grid);
	else
		write(1, "Error", 5);
}

/////////////////////////////////////////////////////////

int	row_leftright(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	i;
	int	highest;
	int	count;

	i = -1;
	highest = 0;
	count = 0;
	while (++i < 4)
	{
		if (attr[2] == grid[attr[0]][i] && i != attr[1])
			return (1);
		if (grid[attr[0]][i] > highest)
		{
			highest = grid[attr[0]][i];
			count++;
		}
		if (grid[attr[0]][i] == -1)
			check = 1;
	}
	if (count > arr[2][attr[0]] && check == 0)
		return (1);
	if (check == 0 && count != arr[2][attr[0]])
		return (1);
	return (0);
}

int	col_updown(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	i;
	int	highest;
	int	count;

	count = 0;
	i = -1;
	highest = 0;
	while (++i < 4)
	{
		if (attr[2] == grid[i][attr[1]] && i != attr[0])
			return (1);
		if (grid[i][attr[1]] > highest)
		{
			highest = grid[i][attr[1]];
			count++;
		}
		if (grid[i][attr[1]] == -1)
			check = 1;
	}
	if (count > arr[0][attr[1]] && check == 0)
		return (1);
	if (check == 0 && count != arr[0][attr[1]])
		return (1);
	return (0);
}

int	rightleft(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = 4;
	while (--i > -1)
	{
		if (grid[attr[0]][i] > highest)
		{
			highest = grid[attr[0]][i];
			count++;
		}
		if (grid[attr[0]][i] == -1)
			check = 1;
	}
	if (count > arr[3][attr[0]] && check == 0)
		return (1);
	if (check == 0 && count != arr[3][attr[0]])
		return (1);
	return (0);
}

int	downup(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = 4;
	while (--i > -1)
	{
		if (grid[i][attr[1]] > highest)
		{
			highest = grid[i][attr[1]];
			count++;
		}
		if (grid[i][attr[1]] == -1)
			check = 1;
	}
	if (count > arr[1][attr[1]] && check == 0)
		return (1);
	if (check == 0 && count != arr[1][attr[1]])
		return (1);
	return (0);
}
/////////////////////////////////////////////////////////


void	initialize(char *str, int *attr, int arr[4][4])
{
	if (attr[1] == 4)
	{
		attr[1] = 0;
		attr[2] += 1;
	}
	arr[attr[2]][attr[1]] = str[attr[0]] - 48;
	attr[1]++;
	attr[0]++;
}

int	input_to_arr(char *str, int *attr, int arr[4][4])
{
	while (str[attr[0]] != '\0')
	{
		if (str[attr[0]] >= '1' && str[attr[0]] <= '4')
			initialize_grid(str, attr, arr);
		else if (str[attr[0]] == ' ')
			++attr[0];
		else
		{
			write(1, "Error", 5);
			return (1);
		}
	}
	if (attr[0] >= 32)
	{
		write(1, "Error", 5);
		return (1);
	}
	return (0);
}

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