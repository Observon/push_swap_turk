/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:17:45 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:17:45 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stack **stack)
{
    t_stack		*tmp;
	int			i;

    tmp = *stack;
    i = 0;
    while (tmp)
    {
        tmp->pos = i;
        i++;
        tmp = tmp->next;
    }
}

void	assign_index(t_stack *stack)
{
    t_stack		*current;
    t_stack	*runner;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}
