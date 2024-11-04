/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:16:18 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/04 13:39:25 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_fill(char *s, unsigned int n, long len)
{
	while (n > 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

long	numlen(int nbr)
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

char	*numtostr(int n, char *str)
{
	long			len;
	unsigned int	nb;

	len = numlen(n);
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
		return (str_fill(str + 1, nb, len - 1));
	}
	else
		nb = n;
	return (str_fill(str, nb, len));
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[100];

	numtostr(n, str);
	ft_putstr_fd(str, fd);
}
