/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:53 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:53 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min_pos(t_stack *stack_a)
{
    t_stack *tmp = stack_a;
    int min_idx = get_min_index(stack_a);
    
    while (tmp)
    {
        if (tmp->index == min_idx)
            return tmp->pos;
        tmp = tmp->next;
    }
    return 0;
}

void shift_stack(t_stack **stack_a)
{
    int size = stack_size(*stack_a);
    int min_pos;
    
    assign_positions(stack_a);
    min_pos = find_min_pos(*stack_a);
    if (min_pos <= size / 2)
    {
        while (min_pos--)
            ra(stack_a, 1);
    }
    else
    {
        while (min_pos++ < size)
            rra(stack_a, 1);
    }
}
