/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:11 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/28 19:16:25 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destanation;
	unsigned char	*source;

	destanation = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		destanation += len;
		source += len;
		while (len-- > 0)
			*(--destanation) = *(--source);
	}
	else
	{
		while (len-- > 0)
			*destanation++ = *source++;
	}
	return (dst);
}
