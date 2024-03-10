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
			initialize(str, attr, arr);
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

