/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:11 by joao-rde          #+#    #+#             */
/*   Updated: 2024/09/23 19:15:32 by joao-rde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sx(t_list **x)
{
    t_list *temp;

    if (!x || !(*x) || !((*x)->next))
        return;
    temp = (*x)->next;
    (*x)->next = temp->next;
    temp->next = (*x);
    *x = temp;
}

void px(t_list **x, t_list **y)
{
    t_list *temp;

    if (!x || !(*x))
        return;
    temp = *x;
    *x = (*x)->next;
    temp->next = *y;
    *y = temp;
}

void rx(t_list **x)
{
    t_list *temp;
    t_list *last;

    if (!x || !(*x) || !((*x)->next))
        return;
    temp = *x;
    *x = (*x)->next;
    temp->next = NULL;
    last = *x;
    while (last->next)
        last = last->next;
    last->next = temp;
}

void rrx(t_list **x)
{
    t_list *last;
    t_list *second_last;

    if (!x || !(*x) || !((*x)->next))
        return;
    last = *x;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *x;
    *x = last;
}

void sa(t_list **stack_a) {
    sx(stack_a);
}

void sb(t_list **stack_b) {
    sx(stack_b);
}

void pa(t_list **x, t_list **y){
    px(x, y);
}

void pb(t_list **x, t_list **y){
    px(y, x);
}

void ra(t_list **x){
    rx(x);
}

void rb(t_list **x){
    rx(x);
}

void rra(t_list **x){
    rrx(x);
}

void rrb(t_list **x){
    rrx(x);
}

void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}

void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}
