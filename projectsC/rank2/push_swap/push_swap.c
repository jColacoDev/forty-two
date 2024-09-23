/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 20:04:50 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_list *create_new_node(int value) {
    int *content = malloc(sizeof(int));
    if (!content)
        return NULL;

    *content = value;

    t_list *new_node = ft_lstnew(content);
    if (!new_node) {
        free(content);
        return NULL;
    }

    return new_node;
}

static t_list *fill_stack_from_args(int argc, char **argv) {
    t_list *stack_a = NULL;
    t_list *new_node = NULL;

    for (int i = 1; i < argc; i++) {
        int value = ft_atoi(argv[i]);
        new_node = create_new_node(value);
        if (!new_node) {
            ft_lstclear(&stack_a, free);
            return NULL;
        }
        ft_lstadd_back(&stack_a, new_node);
    }

    return stack_a;
}

static void push_swap(t_list *stack_a, t_list *stack_b, int len) {
    
    printf("\nlen: %d\n", len);
    
    if (len == 2) {
        if (*(int *)stack_a->content > *(int *)stack_a->next->content)
            sx(&stack_a);
    } else if (len == 3) {
        sort_three_in_a(&stack_a);
    } else if (len <= 20) {
        insertion_sort(&stack_a, &stack_b);
    } else {
        radix_sort(&stack_a, &stack_b);
    }

    printf("\nfinal stack_a: ");
    print_stack(stack_a);
    printf("final stack_b: ");
    print_stack(stack_b);

}

int main(int argc, char **argv)
{
    t_list  *stack_a = NULL;
    t_list  *stack_b = NULL;
    int len;

    len = 0;

    if (argc < 2)
        return (0);
    stack_a = fill_stack_from_args(argc, argv);
    len = ft_lstsize(stack_a);
    
    push_swap(stack_a, stack_b, len);
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}
