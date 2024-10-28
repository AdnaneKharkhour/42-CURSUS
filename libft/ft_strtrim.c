/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:16:30 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/27 15:53:22 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trim(char c, char const	*set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	char	*final;

	start = (char *)s1;
	final = (char *)s1 + (ft_strlen(s1) - 1);
	while (trim(*final, set) == 1)
		final--;
	++final;
	*final = '\0';
	while (trim (*start, set) == 1)
		start++;
	str = malloc(sizeof(char) * (final - start + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, start, (final - start + 1));
	return (str);
}
