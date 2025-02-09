/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:17:58 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/09 12:11:47 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char c, char sep)
{
	return (c == sep);
}

static int	count_words(char const *str, char sep)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		while (check_sep(*str, sep) && *str != '\0')
			str++;
		if (*str != '\0')
			c++;
		while (!check_sep(*str, sep) && *str != '\0')
			str++;
	}
	return (c);
}

static char	*ft_word_allocator(const char *str, char sep)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (!check_sep(str[i], sep) && str[i])
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = str[j];
		j++;
	}
	word[i] = '\0';
	return (word);
}

static char	**free_string(char **string, int i)
{
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		i;

	if (!s)
		return (NULL);
	string = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (check_sep(*s, c) && *s)
			s++;
		if (*s)
		{
			string[i] = ft_word_allocator(s, c);
			if (!string[i])
				return (free_string(string, i));
			i++;
		}
		while (!check_sep(*s, c) && *s)
			s++;
	}
	string[i] = NULL;
	return (string);
}
