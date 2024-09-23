/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 20:04:05 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_max(t_list *a) {
    int max;
    t_list *temp;

    max = *(int *)a->content;
    temp = a;
    while (temp) {
        if (*(int *)temp->content > max)
            max = *(int *)temp->content;
        temp = temp->next;
    }
    return max;
}

static int get_max_bits(t_list *a) {
    int max = find_max(a);
    int bits = 0;
    while (max >> bits)
        bits++;
    return bits;
}

void radix_sort(t_list **a, t_list **b) {
    int max_bits = get_max_bits(*a);
    int size = ft_lstsize(*a);
    int i = 0;

    while (i < max_bits) {
        int j = 0;
        while (j < size) {
            if (((*(int *)(*a)->content >> i) & 1) == 0) {
                px(a, b);
            } else {
                rx(a);
            }
            j++;
        }
        while (ft_lstsize(*b) > 0) {
            px(b, a);
        }
        i++;
    }
}
