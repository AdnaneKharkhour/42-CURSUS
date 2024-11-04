/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:17:58 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/04 11:40:41 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_sep(char c, char sep)
{
	return (c == sep);
}

int	count_words(char const *str, char sep)
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

char	*ft_word(const char *str, char sep)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (!check_sep(str[i], sep) && str[i])
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	j = 0;
	while (str[j] && j < i)
	{
		word[j] = str[j];
		j++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		i;

	if (!s)
		return (NULL);
	string = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!string)
		return (0);
	i = 0;
	while (*s)
	{
		while (check_sep(*s, c) && *s)
			s++;
		if (*s)
		{
			string[i] = ft_word(s, c);
			i++;
		}
		while (!check_sep(*s, c) && *s)
			s++;
	}
	string[i] = 0;
	return (string);
}
