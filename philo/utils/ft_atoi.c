/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:38:35 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/03 15:14:09 by akharkho         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	long	rs;
	int		s;

	s = 1;
	space_sign(&str, &s);
	rs = 0;
	while (ft_isdigit(*str))
	{
		rs = rs * 10 + (*str - '0');
		if ((rs * s) > INT_MAX || (rs * s) < INT_MIN)
			return (-1);
		str++;
	}
	if (*str)
		return (-1337);
	return ((int)(rs * s));
}
