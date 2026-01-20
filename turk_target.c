/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:19:00 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:19:00 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_closest_bigger(t_stack *stack_a, int b_idx)
{
    t_stack *tmp = stack_a;
    int target_idx = INT_MAX;
    int target_pos = 0;
    
    while (tmp)
    {
        if (tmp->index > b_idx && tmp->index < target_idx)
        {
            target_idx = tmp->index;
            target_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return target_pos;
}

static int find_smallest_pos(t_stack *stack_a)
{
    t_stack *tmp = stack_a;
    int target_idx = INT_MAX;
    int target_pos = 0;
    
    while (tmp)
    {
        if (tmp->index < target_idx)
        {
            target_idx = tmp->index;
            target_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return target_pos;
}

int get_target_position(t_stack *stack_a, int b_idx)
{
    int target_pos;
    
    target_pos = find_closest_bigger(stack_a, b_idx);
    if (target_pos == 0 && stack_a->index <= b_idx)
        target_pos = find_smallest_pos(stack_a);
    return target_pos;
}

void get_target_positions(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b = *stack_b;
    
    assign_positions(stack_a);
    assign_positions(stack_b);
    while (tmp_b)
    {
        tmp_b->target_pos = get_target_position(*stack_a, tmp_b->index);
        tmp_b = tmp_b->next;
    }
}
