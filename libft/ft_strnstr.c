/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:30:00 by eride-ol          #+#    #+#             */
/*   Updated: 2025/10/28 19:30:00 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len > len)
		return (NULL);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
