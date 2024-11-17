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

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr(const char *s, int c)
{
	int i;

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
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
	char    *str;
	size_t  final;
	size_t  slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
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

	if (!s2)
		return (NULL);
	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	str = (char *)malloc(sizeof (char) * (s1_len + ft_strlen(s2) + 1));
	if (!str)
	{
		free (s1);
		return (NULL);
	}
	if (s1)
	{
		ft_strlcpy(str, s1, s1_len + 1);
		free(s1);
	}
	ft_strlcpy(str + s1_len, s2, ft_strlen(s2) + 1);
	return (str);
}