/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:17:58 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/10 18:19:40 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

static int	check_sep(char c, char sep)
{
	return (c == sep);
}

static int	count_words(char const *str, char sep)
{
	int	c;
	int	quote;

	c = 0;
	quote = 0;
	while (*str != '\0')
	{
		if (*str == '\'' || *str == '\"')
			quote = !quote;
		if (!quote && check_sep(*str, sep))
			c++;
		str++;
	}
	return (c + 1);
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
	int		quote;

	if (!s)
		return (NULL);
	string = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!string)
		return (NULL);
	i = 0;
	quote = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"')
			quote = !quote;
		if (!quote && check_sep(*s, c))
		{
			string[i] = ft_word_allocator(s, c);
			if (!string[i])
				return (free_string(string, i));
			i++;
		}
		s++;
	}
	string[i] = NULL;
	return (string);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./a.out <command>\n");
		return 1;
	}

	char const *s = argv[1];
	char c = ' ';
	char **result = ft_split(s, c);
	if (result)
	{
		int i = 0;
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
		free(result);
	}
	return 0;
}
