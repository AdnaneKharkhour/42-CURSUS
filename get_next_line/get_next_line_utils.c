#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t  i;

	if (!dst || !src)
			return (ft_strlen(src));
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
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *str;
	size_t  final;
	size_t  slen;

	if (!s)
			return ((char *)s);
	slen = ft_strlen(s);
	if (start >= slen)
			return (ft_strdup(""));
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

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}