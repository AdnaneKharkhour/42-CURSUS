/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:03:55 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/15 15:04:32 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_quotes(const char *str, int *in_quote)
{
	if (*str == '\'')
		*in_quote = !(*in_quote);
}

char	**free_string(char **string, int i)
{
	while (i >= 0)
	{
		free(string[i]);
		i--;
	}
	free(string);
	return (NULL);
}
