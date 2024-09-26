
#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				top;
	unsigned int	size;
	int				*array;
}					t_stack;

t_stack	*initialize(unsigned int size);
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
int		max(t_stack *stack);
int		min(t_stack *stack);

#endif