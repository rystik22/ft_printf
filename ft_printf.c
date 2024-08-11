/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:21:25 by rradin-m          #+#    #+#             */
/*   Updated: 2024/08/10 14:28:46 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_printf_check(va_list arg, const char s)
{
	if (s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (s == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (s == 'd' || s == 'i')
		return (ft_num(va_arg(arg, int)));
	else if (s == 'p')
		return (ft_pointer((unsigned long long)va_arg(arg, void *)));
	else if (s == 'u')
		return (ft_putnum_unsign(va_arg(arg, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), s));
	else if (s == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(s));
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += ft_printf_check (arg, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}

#include <stdio.h>
int main(void)
{
	printf("dasd%s %dweqe", "hello", 2);
}