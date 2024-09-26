
#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"

# define INSTRUCTIONS_BUFFER_SIZE 4096

bool	binary_search(int n, int *data, int size);
int	    get_instructions(char ***instructions);
int	    execute(char **instructions, t_stack *stack);

#endif