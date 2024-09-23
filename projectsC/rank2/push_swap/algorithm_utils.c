/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 18:58:40 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_stack(t_list *stack)
{
    t_list *current = stack;

    while (current) {
        printf("%d ", *(int *)(current->content));  // Assuming content is an integer pointer
        current = current->next;
    }
    printf("\n");
}

int find_min(t_list *x) {
    int min;
    t_list *temp;

    min = *(int *)x->content;
    temp = x;
    while (temp) {
        if (*(int *)temp->content < min)
            min = *(int *)temp->content;
        temp = temp->next;
    }
    return min;
}

static int find_pos(int val, t_list *x) {
    int pos;

    pos = 0;
    while (x) {
        if (*(int *)x->content == val)
            return pos;
        x = x->next;
        pos++;
    }
    return pos;
}

void rotate_to_top(int val, t_list **x) {
    int pos;
    int size;

    pos = find_pos(val, *x);
    size = ft_lstsize(*x);
    if (pos <= size / 2) {
        while (*(int *)(*x)->content != val)
            rx(x);
    } else {
        while (*(int *)(*x)->content != val)
            rrx(x);
    }
}

void sort_three_in_a(t_list **x) {
    int first = *(int *)(*x)->content;
    int second = *(int *)(*x)->next->content;
    int third = *(int *)(*x)->next->next->content;

    if (first > second && second < third) {
        if (first > third)
            sx(x);
    } else if (first > second && second > third) {
        sx(x);
        rrx(x);
    } else if (first > second && second < third) {
        rx(x);
    } else if (first < second && second > third && first > third) {
        rrx(x);
    } else if (first < second && second > third) {
        sx(x);
        rx(x);
    }
}
