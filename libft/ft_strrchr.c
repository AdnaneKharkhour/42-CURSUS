/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:48:55 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/24 15:27:51 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	size_t	len;
	char	ch;

	len = ft_strlen(s);
	ch = (char) c;
	while (len > 0)
	{
		if (s[len - 1] == ch)
			return ((char *)s + len - 1);
		len--;
	}
	return ((char *)s + len);
}
