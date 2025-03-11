/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:04:01 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/18 15:39:55 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
	int		len;
	int		in_qoute;
	char	*word;

	len = 0;
	in_qoute = 0;
	while (str[len] && (!check_sep(str[len], sep) || in_qoute))
	{
		ft_quotes(&str[len], &in_qoute);
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] != '\'')
			word[j++] = str[i];
		i++;
	}
	return (word[i] = '\0', word);
}

char	**split_string(const char *s, char c, char **string)
{
	int	i;
	int	in_quote;

	i = 0;
	in_quote = 0;
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
		while (*s && (!check_sep(*s, c) || in_quote))
		{
			ft_quotes(s, &in_quote);
			s++;
		}
	}
	string[i] = NULL;
	return (string);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**string;

	if (!s)
		return (NULL);
	string = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!string)
		return (NULL);
	return (split_string(s, c, string));
}
