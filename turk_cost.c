/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:45 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:45 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *stack_b;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	if (cost_a < 0)
		abs_a = -cost_a;
	else
		abs_a = cost_a;
	if (cost_b < 0)
		abs_b = -cost_b;
	else
		abs_b = cost_b;
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

void	find_cheapest(t_stack *stack_b, int *cost_a, int *cost_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		total_cost;

	tmp = stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		total_cost = calculate_total_cost(tmp->cost_a, tmp->cost_b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			*cost_a = tmp->cost_a;
			*cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
}

static void do_double_rotations(t_stack **stack_a, t_stack **stack_b,
                                int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(stack_a, stack_b, 1);
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(stack_a, stack_b, 1);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void do_single_rotations(t_stack **stack_a, t_stack **stack_b,
                                int cost_a, int cost_b)
{
    while (cost_a > 0)
    {
        ra(stack_a, 1);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(stack_a, 1);
        cost_a++;
    }
    while (cost_b > 0)
    {
        rb(stack_b, 1);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(stack_b, 1);
        cost_b++;
    }
}

void execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    int cost_a = 0;
    int cost_b = 0;
    
    find_cheapest(*stack_b, &cost_a, &cost_b);
    do_double_rotations(stack_a, stack_b, &cost_a, &cost_b);
    do_single_rotations(stack_a, stack_b, cost_a, cost_b);
    pa(stack_a, stack_b, 1);
}
