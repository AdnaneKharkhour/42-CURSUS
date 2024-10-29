/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:24 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/29 12:51:43 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const	void *src, size_t n)
{
	unsigned char		*destinaion;
	const unsigned char	*source;

	if (!dst && !src)
		return (dst);
	destinaion = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (n > 0)
	{
		*destinaion = *source;
		destinaion++;
		source++;
		n--;
	}
	return (dst);
}
