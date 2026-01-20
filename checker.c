/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:45:00 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 19:45:00 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_error(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	error_exit();
}

static int	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

static void	read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ret = execute_instruction(line, stack_a, stack_b);
		free(line);
		if (!ret)
			checker_error(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	read_and_execute(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
