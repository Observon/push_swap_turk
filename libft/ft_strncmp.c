/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:30:00 by eride-ol          #+#    #+#             */
/*   Updated: 2025/10/28 19:30:00 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && s1[i] && s1[i] == s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
