/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:19:14 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:19:14 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(char *str)
{
    int i;
    
    i = 0;
    if (!str || !*str)
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int has_duplicates(t_stack *stack)
{
    t_stack *tmp1;
    t_stack *tmp2;
    
    tmp1 = stack;
    while (tmp1)
    {
        tmp2 = tmp1->next;
        while (tmp2)
        {
            if (tmp1->value == tmp2->value)
                return (1);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    return (0);
}

int is_sorted(t_stack *stack)
{
    if (!stack || !stack->next)
        return (1);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}
