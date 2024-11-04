/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:08:31 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/04 11:55:23 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*string_fill(char *s, unsigned int n, long len)
{
	while (n > 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

long	numb_len(int nbr)
{
	long	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	long			len;
	unsigned int	nb;

	len = numb_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	str = string_fill(str, nb, len);
	return (str);
}
