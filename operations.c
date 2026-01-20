/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:01 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:01 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack_a, int print)
{
    t_stack *first;
    t_stack *second;
    
    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    if (print)
        write(1, "sa\n", 3);
}

void sb(t_stack **stack_b, int print)
{
    t_stack *first;
    t_stack *second;
    
    if (!*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    if (print)
        write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a, 0);
    sb(stack_b, 0);
    write(1, "ss\n", 3);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (!*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
    write(1, "pa\n", 3);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (!*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}

void ra(t_stack **stack_a, int print)
{
    t_stack *first;
    t_stack *last;
    
    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    *stack_a = first->next;
    last = get_bottom(*stack_a);
    last->next = first;
    first->next = NULL;
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack **stack_b, int print)
{
    t_stack *first;
    t_stack *last;
    
    if (!*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    *stack_b = first->next;
    last = get_bottom(*stack_b);
    last->next = first;
    first->next = NULL;
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a, 0);
    rb(stack_b, 0);
    write(1, "rr\n", 3);
}
