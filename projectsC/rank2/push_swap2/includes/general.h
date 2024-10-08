
#ifndef GENERAL_H
# define GENERAL_H

# include "stack.h"
# include <stdbool.h>
# include <stdlib.h>

# define SPACE ' '
# define STACK_BUFFER 1024

void	free_array(void **array);
void	free_stack(t_stack *stack);
void	message_and_exit(t_stack *stack, char **ops, int status);
bool	is_sorted(t_stack *stack);
void	insertion_sort(int array[], size_t size);
t_stack	*parse_stack(int size, char **args);

#endif