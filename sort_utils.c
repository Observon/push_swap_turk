/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:30 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:30 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *stack, int min_idx)
{
	int	pos;
	
	pos = 0;
	while (stack && stack->index != min_idx)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	rotate_to_min(t_stack **stack_a, int size)
{
	int	min_idx;
	int	pos;
	
	min_idx = get_min_index(*stack_a);
	pos = find_min_position(*stack_a, min_idx);
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
