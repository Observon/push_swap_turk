/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:05:51 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/27 11:28:35 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*str_joined;
	int		i;
	int		j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	str_joined = malloc(sizeof(char) * (total_size + 1));
	if (!str_joined || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		str_joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		str_joined[i++] = s2[j++];
	str_joined[total_size] = 0;
	return (str_joined);
}

char	*ft_strchr(const char *string, int seachchar)
{
	char	*str;

	str = (char *)string;
	while (*str != seachchar && *str != 0)
		str++;
	if (*str == seachchar)
		return (str);
	else
		return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;
	size_t	total;

	result = malloc(size * count);
	if (!result)
		return (NULL);
	total = size * count;
	i = 0;
	while (i < total)
		result[i++] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
