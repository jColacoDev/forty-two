#include "./../../includes/push_swap.h"

t_stack	*initialize_stack(unsigned int size)
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

static bool	validate_int(char *elem)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i]))
			is_int = false;
		i++;
	}
	return (!is_int);
}

static bool	already_exists(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == n)
			return (true);
		i--;
	}
	return (false);
}

static int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, SPACE);
	while (array[j] && !status)
	{
		if (validate_int(array[j]))
			status = 1;
		if (atoiv(array[j], &n))
			status = 2;
		if (already_exists(n, stack))
			status = 3;
		else
			stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array);
	return (status);
}

t_stack	*parse_stack(int size, char **args)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize_stack(STACK_BUFFER);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
	{
		free_stack(stack);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(status);
	}
	ft_array_r(stack->array, stack->top + 1);
	return (stack);
}
