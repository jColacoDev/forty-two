
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"
# include "checker.h"
# include "general.h"

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

# define CHUNK_CONSTANT 50
# define SORT_COMPLEX_LIMIT 5

int		_index(t_stack *stack, int n);
void	sort(t_stack *stack);
void	run_op(char *op, t_stack *a, t_stack *b);
void	run_ops(char *op, t_stack *a, t_stack *b, int n);
void	index_stack(t_stack **stack);
void	sort_small(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
void	smart_rotate_a(t_stack *a, int n);
void	smart_rotate_b(t_stack *b, int n);
int		closest_above(t_stack *a, int n);
int		closest_below(t_stack *a, int n);
void	move_to_top(t_stack *a, int min, int max);
void	move_min_or_max_to_top(t_stack *b);

#endif