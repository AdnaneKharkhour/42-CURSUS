/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:48:55 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/29 11:17:56 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = (int)ft_strlen(s);
	ch = (char)c;
	if (ch == '\0')
		return ((char *)(s + len));
	while (len >= 0)
	{
		if (s[len] == ch)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
