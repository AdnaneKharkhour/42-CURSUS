/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:41:43 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/26 19:02:31 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(const char *format, va_list args, int *count)
{
	if (*format == 'd' || *format == 'i')
		*count += ft_putnbr(va_arg(args, int));
	else if (*format == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (*format == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (*format == 'x')
		*count += ft_putnbr_base(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		*count += ft_putnbr_base(va_arg(args, unsigned int), 1);
	else if (*format == 'u')
		*count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'p')
	{
		*count += ft_putstr("0x");
		*count += ft_putnbr_base(va_arg(args, unsigned long int), 0);
	}
	else if (*format == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (write(1, NULL, 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			check_format(format, args, &count);
		}
		else if (*format != '%')
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
