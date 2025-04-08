/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:38:35 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/05 16:35:38 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

	s = 1;
	space_sign(&str, &s);
	rs = 0;
	while (ft_isdigit(*str))
	{
		if (rs > (LONG_MAX - *str - '\0') / 10)
			return (-1);
		rs = rs * 10 + (*str - '0');
		str++;
	}
	if (*str)
		return (-1337);
	return (rs * s);
}
