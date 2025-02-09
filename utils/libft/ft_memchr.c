/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:41:58 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/29 12:43:58 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			ch;
	const unsigned char		*ptr;

	ch = (unsigned char)c;
	ptr = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
