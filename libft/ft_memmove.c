/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:35:00 by eride-ol          #+#    #+#             */
/*   Updated: 2025/10/30 03:35:00 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (!dst && !src)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	if (dst < src)
	{
		while (n-- > 0)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		dst_ptr += n;
		src_ptr += n;
		while (n-- > 0)
			*--dst_ptr = *--src_ptr;
	}
	return (dst);
}
