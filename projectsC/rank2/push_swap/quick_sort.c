/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 19:59:17 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int find_pivot(t_list *stack, int size) {
    int *values = malloc(size * sizeof(int));
    if (!values) return 0;

    for (int i = 0; i < size; i++) {
        values[i] = *(int *)stack->content;
        stack = stack->next;
    }

    // Simple bubble sort to find the median
    for (int j = 0; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
            if (values[j] > values[k]) {
                int temp = values[j];
                values[j] = values[k];
                values[k] = temp;
            }
        }
    }

    int pivot = values[size / 2];
    free(values);
    return pivot;
}

static void push_to_b(t_list **stack_a, t_list **stack_b, int pivot) {
    int size = ft_lstsize(*stack_a);
    for (int i = 0; i < size; i++) {
        if (*(int *)(*stack_a)->content < pivot) {
            pb(stack_a, stack_b);
        } else {
            ra(stack_a);
        }
    }
}

void quick_sort(t_list **stack_a, t_list **stack_b) {
    int size_a = ft_lstsize(*stack_a);
    if (size_a <= 1) return;

    int pivot = find_pivot(*stack_a, size_a);
    push_to_b(stack_a, stack_b, pivot);

    // Only continue if stack_b has elements
    if (ft_lstsize(*stack_b) > 0) {
        quick_sort(stack_b, stack_a); // Sort stack_b
    }
    
    // Now sort stack_a
    quick_sort(stack_a, stack_b); // Sort stack_a

    // Move elements back to stack_a
    while (ft_lstsize(*stack_b) > 0) {
        pa(stack_a, stack_b);
    }
}
