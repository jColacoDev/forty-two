#include "push_swap.h"

t_stack	*initialize(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!(stack))
		return (NULL);
	stack->array = malloc(size * sizeof(*(stack->array)));
	if (!(stack->array))
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

static int	_max(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _max(array, len - 1);
	if (array[len - 1] > m)
		m = array[len - 1];
	return (m);
}

int	max(t_stack *stack)
{
	return (_max(stack->array, stack->top + 1));
}


static int	_min(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _min(array, len - 1);
	if (array[len - 1] < m)
		m = array[len - 1];
	return (m);
}

int	min(t_stack *stack)
{
	return (_min(stack->array, stack->top + 1));
}

void	push(t_stack *from, t_stack *to)
{
	if (from->top == -1)
		return ;
	to->array[++to->top] = from->array[from->top--];
}


void	rotate(t_stack *stack)
{
	unsigned int	i;
	int				tmp;

	i = stack->top + 1;
	tmp = stack->array[stack->top];
	while (--i)
		stack->array[i] = stack->array[i - 1];
	stack->array[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->array[0];
	while (++i < stack->top)
		stack->array[i] = stack->array[i + 1];
	stack->array[stack->top] = tmp;
}

void	swap(t_stack *stack)
{
	int	aux;

	if (stack->top <= 0)
		return ;
	aux = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = aux;
}