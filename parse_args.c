/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:12 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:12 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long set_limit(int sign)
{
    if (sign == 1)
        return (long)INT_MAX;
    return (long)INT_MIN * -1;
}

static int check_overflow(long result, long limit, char c)
{
    long digit;
    
    digit = c - '0';
    if (result > (limit - digit) / 10)
        return 0;
    return 1;
}

static int	parse_sign_and_skip(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int parse_int(const char *str, int *out)
{
    int sign;
    long result;
    long limit;

    sign = 1;
    result = 0;
    if (!str || !*str)
        return 0;
    sign = parse_sign_and_skip(&str);
    if (!*str)
        return 0;
    limit = set_limit(sign);
    while (*str)
    {
        if (!ft_isdigit(*str))
            return 0;
        if (!check_overflow(result, limit, *str))
            return 0;
        result = result * 10 + (*str - '0');
        str++;
    }
    *out = (int)(result * sign);
    return 1;
}

static int validate_and_add(char *num_str, t_stack **stack_a)
{
    int num;

    if (!is_valid_number(num_str))
        return 0;
    if (!parse_int(num_str, &num))
        return 0;
    stack_add_back(stack_a, create_node(num));
    return 1;
}

static void free_split(char **split)
{
    int i = 0;
    
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

static int process_split(char **nums, t_stack **stack_a)
{
    int j = 0;
    
    while (nums[j])
    {
        if (!validate_and_add(nums[j], stack_a))
        {
            free_split(nums);
            free_stack(stack_a);
            error_exit();
        }
        j++;
    }
    return 1;
}

t_stack *parse_arguments(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    char **nums;
    int i = 1;
    
    while (i < argc)
    {
        if (!argv[i] || !*argv[i])
            error_exit();
        nums = ft_split(argv[i], ' ');
        if (!nums || !nums[0])
        {
            free_split(nums);
            free_stack(&stack_a);
            error_exit();
        }
        process_split(nums, &stack_a);
        free_split(nums);
        i++;
    }
    if (has_duplicates(stack_a))
    {
        free_stack(&stack_a);
        error_exit();
    }
    return stack_a;
}
