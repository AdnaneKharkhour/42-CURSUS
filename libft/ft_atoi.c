/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:38:35 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/07 17:28:16 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	space_sign(const char *s, int *sign)
{
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*sign *= -1; 
		s++;
	}
}

int	ft_atoi(const char *str)
{
	long	rs;
	int		s;

	s = 1;
	space_sign(str, &s);
	rs = 0;
	while (ft_isdigit(*str))
	{
		if (rs > (LONG_MAX - *str - '\0') / 10)
		{
			if (s == 1)
				return (-1);
			else
				return (0);
		}
		rs = rs * 10 + (*str - '0');
		str++;
	}
	return (rs * s);
}
