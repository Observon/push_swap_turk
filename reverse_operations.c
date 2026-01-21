/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:23 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:23 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **stack_a, int print)
{
    t_stack *last;
    t_stack *before_last;
    
    if (!*stack_a || !(*stack_a)->next)
        return;
    before_last = *stack_a;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b, int print)
{
    t_stack *last;
    t_stack *before_last;
    
    if (!*stack_b || !(*stack_b)->next)
        return;
    before_last = *stack_b;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
}
