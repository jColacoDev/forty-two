/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 19:51:29 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(t_list **a, t_list **b) {
    int min;

    while (ft_lstsize(*a) > 3) {
        min = find_min(*a);
        rotate_to_top(min, a);
        px(a, b);
    }
    sort_three_in_a(a);
    while (ft_lstsize(*b) > 0)
        px(b, a);
    if (ft_lstsize(*a) > 1 && *(int *)(*a)->content > *(int *)(*a)->next->content)
        sx(a);
}
