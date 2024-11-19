/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:30:45 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/17 11:30:45 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	final;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = 0;
	while (s[slen])
		slen++;
	final = slen - start;
	if (final > len)
		final = len;
	str = (char *)malloc(sizeof(char) * (final + 1));
	if (!str)
		return (0);
	ft_strlcpy (str, (char *)(s + start), final + 1);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	if (s1)
	{
		while (s1[s1_len])
			s1_len++;
	}
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (!str)
		return (free(s1), NULL);
	if (s1)
	{
		ft_strlcpy(str, s1, s1_len + 1);
		free(s1);
	}
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}
