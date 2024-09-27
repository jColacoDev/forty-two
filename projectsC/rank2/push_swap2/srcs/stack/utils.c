#include "./../../includes/push_swap.h"

static int	_max(int *array, size_t len)
{
	int	max;

	if (len == 1)
		return (array[0]);
	max = _max(array, len - 1);
	if (array[len - 1] > max)
		max = array[len - 1];
	return (max);
}

int	max(t_stack *stack)
{
	return (_max(stack->array, stack->top + 1));
}

static int	_min(int *array, size_t len)
{
	int	min;

	if (len == 1)
		return (array[0]);
	min = _min(array, len - 1);
	if (array[len - 1] < min)
		min = array[len - 1];
	return (min);
}

int	min(t_stack *stack)
{
	return (_min(stack->array, stack->top + 1));
}
