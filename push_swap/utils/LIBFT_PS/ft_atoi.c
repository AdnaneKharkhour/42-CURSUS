/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:38:35 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/08 18:33:20 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	space_sign(const char **s, int *sign)
{
	while (**s == 32 || (**s >= 9 && **s <= 13))
		(*s)++;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			*sign *= -1; 
		(*s)++;
	}
}

long	ft_atoi(const char *str)
{
	long	rs;
	int		s;
	long	prev_rs;

	s = 1;
	space_sign(&str, &s);
	rs = 0;
	while (ft_isdigit(*str))
	{
		prev_rs = rs;
		rs = rs * 10 + (*str - '0');
		if ((rs / 10) != prev_rs)
		{
			if (s == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		str++;
	}
	return (rs * s);
}
