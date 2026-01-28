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

int	get_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stack **stack)
{
	int	max;
	
	max = get_max_index(*stack);
	if ((*stack)->index == max)
		ra(stack, 1);
	else if ((*stack)->next->index == max)
		rra(stack, 1);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack, 1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = stack_size(*stack_a);
	while (size > 3)
	{
		rotate_to_min(stack_a, size);
		pb(stack_a, stack_b, 1);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
