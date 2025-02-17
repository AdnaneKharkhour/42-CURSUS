/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:05:24 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/15 18:30:06 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_memcpy(void *dst, const	void *src, size_t n)
{
	char		*destination;
	const char	*source;

	if (dst == src)
		return (dst);
	destination = (char *)dst;
	source = (const char *)src;
	while (n > 0)
	{
		*destination = *source;
		destination++;
		source++;
		n--;
	}
	return (dst);
}
