/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:16:30 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/04 11:40:57 by akharkho         ###   ########.fr       */
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
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	final = (char *)s1 + ft_strlen(s1) - 1;
	while (trim(*final, set) && final >= start)
		final--;
	while (trim (*start, set) && start <= final)
		start++;
	len = final - start + 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, start, len + 1);
	return (str);
}
