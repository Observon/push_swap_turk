/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:30 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:30 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min_index(t_stack *stack)
{
    int min = stack->index;
    
    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return min;
}

int get_max_index(t_stack *stack)
{
    int max = stack->index;
    
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return max;
}

void sort_three(t_stack **stack)
{
    int max = get_max_index(*stack);
    
    if ((*stack)->index == max)
        ra(stack, 1);
    else if ((*stack)->next->index == max)
        rra(stack, 1);
    if ((*stack)->index > (*stack)->next->index)
        sa(stack, 1);
}

static int find_min_position(t_stack *stack, int min_idx)
{
    int pos = 0;
    
    while (stack && stack->index != min_idx)
    {
        pos++;
        stack = stack->next;
    }
    return pos;
}

static void rotate_to_min(t_stack **stack_a, int size)
{
    int min_idx = get_min_index(*stack_a);
    int pos = find_min_position(*stack_a, min_idx);
    
    assign_positions(stack_a);
    if (pos <= size / 2)
    {
        while ((*stack_a)->index != min_idx)
            ra(stack_a, 1);
    }
    else
    {
        while ((*stack_a)->index != min_idx)
            rra(stack_a, 1);
    }
}

void sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    
    while (size > 3)
    {
        rotate_to_min(stack_a, size);
        pb(stack_a, stack_b);
        size--;
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}
