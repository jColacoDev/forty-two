#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top)
	{
		if (stack->array[i + 1] > stack->array[i])
			return (false);
	}
	return (true);
}

void	insertion_sort(int array[], size_t size)
{
	int				i;
	unsigned int	j;
	int				key;

	j = 1;
	while (j < size)
	{
		i = j - 1;
		key = array[j++];
		while (i >= 0 && array[i + 1] < array[i])
		{
			array[i + 1] = array[i];
			array[i--] = key;
		}
	}
}

bool	binary_search(int n, int *data, int size)
{
	int	mid;
	int	left;
	int	right;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (data[mid] == n)
			return (true);
		else if (n < data[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (false);
}
