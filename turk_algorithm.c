/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:37 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:37 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
    int pushed = 0;
    int i = 0;
    
    while (size > 3 && i < size && pushed < size - 3)
    {
        if ((*stack_a)->index <= size - 3)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a, 1);
        i++;
    }
}

void turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    
    push_to_b(stack_a, stack_b, size);
    sort_three(stack_a);
    while (*stack_b)
    {
        get_target_positions(stack_a, stack_b);
        calculate_costs(stack_a, stack_b);
        execute_cheapest_move(stack_a, stack_b);
    }
    if (!is_sorted(*stack_a))
        shift_stack(stack_a);
}
