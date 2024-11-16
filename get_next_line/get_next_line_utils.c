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
	size_t  i;

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
	while (s1[i])
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