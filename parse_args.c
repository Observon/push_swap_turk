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

static int	validate_and_add(char *num_str, t_stack **stack_a)
{
	int	num;

	if (!is_valid_number(num_str))
		return (0);
	if (!parse_int(num_str, &num))
		return (0);
	stack_add_back(stack_a, create_node(num));
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	process_split(char **nums, t_stack **stack_a)
{
	int	j;

	j = 0;
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
	return (1);
}

static void	process_arg(char *arg, t_stack **stack_a)
{
	char	**nums;

	if (!arg || !*arg)
	{
		free_stack(stack_a);
		error_exit();
	}
	nums = ft_split(arg, ' ');
	if (!nums || !nums[0])
	{
		free_split(nums);
		free_stack(stack_a);
		error_exit();
	}
	process_split(nums, stack_a);
	free_split(nums);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		process_arg(argv[i], &stack_a);
		i++;
	}
	if (has_duplicates(stack_a))
	{
		free_stack(&stack_a);
		error_exit();
	}
	return (stack_a);
}
