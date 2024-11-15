/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:55:01 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/09 12:28:45 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	final;
	size_t	slen;

	if (!s)
		return ((char *)s);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, sizeof(char)));
	final = slen - start;
	if (final > len)
		final = len;
	str = (char *)malloc(sizeof(char) * (final + 1));
	if (!str)
		return (0);
	ft_strlcpy (str, (char *)(s + start), final + 1);
	return (str);
}
