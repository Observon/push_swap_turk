/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:12 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:12 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	set_limit(int sign)
{
	if (sign == 1)
		return ((long)INT_MAX);
	return ((long)INT_MIN * -1);
}

static int	check_overflow(long result, long limit, char c)
{
	long	digit;
	
	digit = c - '0';
	if (result > (limit - digit) / 10)
		return (0);
	return (1);
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

int	parse_int(const char *str, int *out)
{
	int		sign;
	long	result;
	long	limit;

	sign = 1;
	result = 0;
	if (!str || !*str)
		return (0);
	sign = parse_sign_and_skip(&str);
	if (!*str)
		return (0);
	limit = set_limit(sign);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		if (!check_overflow(result, limit, *str))
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	*out = (int)(result * sign);
	return (1);
}
