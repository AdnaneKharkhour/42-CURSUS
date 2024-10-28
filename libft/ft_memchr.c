/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:41:58 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/25 11:04:41 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	const char		*ptr;

	ch = (unsigned char)c;
	ptr = (const char *)s;
	while (n > 0)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (0);
}
