/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:59:12 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/09 13:44:35 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}
