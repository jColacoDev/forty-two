
#include <unistd.h>

void	initialize_grid(int arr[4][4], int grid[4][4]);
int		recursion(int grid[4][4], int arr[4][4], int r, int c);
void	print_criteria(int arr[4][4]);
void	init_grid(int arr[4][4], int grid[4][4]);
int     check_vertical(int check, int *attr, int grid[4][4], int arr[4][4], int direction);
int     check_horizontal(int check, int *attr, int grid[4][4], int arr[4][4], int direction);

int	is_valid(int grid[4][4], int arr[4][4], int *attr)
{
	grid[attr[0]][attr[1]] = attr[2];
	if (check_horizontal(0, attr, grid, arr, 0) == 1)
		return (1);
	if (check_vertical(0, attr, grid, arr, 0) == 1)
		return (1);
	if (check_horizontal(0, attr, grid, arr, 1) == 1)
		return (1);
	if (check_vertical(0, attr, grid, arr, 1) == 1)
		return (1);
	return (0);
}

int	condition(int arr[4][4], int row, int col)
{
	if ((row == 0) && (arr[0][col] == 2 || arr[0][col] == 3))
		return (1);
	if ((row == 3) && (arr[1][col] == 2 || arr[1][col] == 3))
		return (1);
	if ((col == 0) && (arr[2][row] == 2 || arr[2][row] == 3))
		return (1);
	if ((col == 3) && (arr[3][row] == 2 || arr[3][row] == 3))
		return (1);
	return (0);
}

int	condition_loop(int *i, int *attr, int arr[4][4], int grid[4][4])
{
	int	row;
	int	col;

	row = attr[0];
	col = attr[1];
	while (++*i < 5)
	{
		if (*i == 4 && (attr[0] == 0 || attr[1] == 0 
			|| attr[0] == 3 || attr[1] == 3))
		{
			if (condition(arr, row, col) == 1)
				continue ;
		}
		attr[2] = *i;
		if (is_valid(grid, arr, attr) == 0)
		{
			if (recursion(grid, arr, row, col + 1) == 0)
				return (0);
			grid[row][col] = -1;
		}
		else
			grid[row][col] = -1;
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

void	puzzle_algorithm(int arr[4][4])
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
	initialize_grid(arr, grid);
	ans = recursion(grid, arr, 0, 0);
	if (ans == 0)
		print_criteria(grid);
	else
		write(1, "Error", 5);
}

int check_vertical(int check, int *attr, int grid[4][4], int arr[4][4], int direction) {
    int count = 0;
    int highest = 0;
    int i;

    if (direction == 0) {
        i = -1;
        while (++i < 4) {
            if (attr[2] == grid[i][attr[1]] && i != attr[0])
                return 1;
            if (grid[i][attr[1]] > highest) {
                highest = grid[i][attr[1]];
                count++;
            }
            if (grid[i][attr[1]] == -1)
                check = 1;
        }
        if (count > arr[0][attr[1]] && check == 0)
            return 1;
        if (check == 0 && count != arr[0][attr[1]])
            return 1;
    } else {
        i = 4;
        while (--i > -1) {
            if (grid[i][attr[1]] > highest) {
                highest = grid[i][attr[1]];
                count++;
            }
            if (grid[i][attr[1]] == -1)
                check = 1;
        }
        if (count > arr[1][attr[1]] && check == 0)
            return 1;
        if (check == 0 && count != arr[1][attr[1]])
            return 1;
    }
    return 0;
}

int check_horizontal(int check, int *attr, int grid[4][4], int arr[4][4], int direction) {
    int count = 0;
    int highest = 0;
    int i;

    if (direction == 0) {
        i = -1;
        while (++i < 4) {
            if (attr[2] == grid[attr[0]][i] && i != attr[1])
                return 1;
            if (grid[attr[0]][i] > highest) {
                highest = grid[attr[0]][i];
                count++;
            }
            if (grid[attr[0]][i] == -1)
                check = 1;
        }
        if (count > arr[2][attr[0]] && check == 0)
            return 1;
        if (check == 0 && count != arr[2][attr[0]])
            return 1;
    } else {
        i = 4;
        while (--i > -1) {
            if (grid[attr[0]][i] > highest) {
                highest = grid[attr[0]][i];
                count++;
            }
            if (grid[attr[0]][i] == -1)
                check = 1;
        }
        if (count > arr[3][attr[0]] && check == 0)
            return 1;
        if (check == 0 && count != arr[3][attr[0]])
            return 1;
    }
    return 0;
}

