/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:01 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:01 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
