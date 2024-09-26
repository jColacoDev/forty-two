#include "./../../includes/push_swap.h"

bool	atoiv(const char *str, int *n)
{
	int		signal;
	bool	overflow;

	*n = 0;
	signal = -1;
	overflow = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = 1;
	while (*str >= '0' && *str <= '9')
	{
		*n = *n * 10 - (*str++ - '0');
		if (*n > 0 || (*n == INT_MIN && signal < 0))
			overflow = true;
	}
	*n *= signal;
	return (overflow);
}

static void	_swap(int *a, int *b)
{
	int	aux;

	aux = *b;
	*b = *a;
	*a = aux;
}

void	reverse_array(int *array, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		_swap(&array[i++], &array[size - 1]);
		reverse_array(array, size - 1);
	}
	i = 0;
}

int	abs(int n)
{
	int	mask;

	mask = n >> 31;
	return ((n ^ mask) - mask);
}
