/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:41:27 by rradin-m          #+#    #+#             */
/*   Updated: 2024/07/31 16:32:56 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_num(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr ("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar ('-');
		n = -n;
	}
	if (n > 9)
		len += ft_num(n / 10);
	len += ft_putchar ((n % 10) + '0');
	return (len);
}

ssize_t	ft_putnum_unsign(unsigned int n)
{
	ssize_t	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnum_unsign (n / 10);
		len += ft_putchar ((n % 10) + '0');
	}
	else
	{
		len += ft_putchar('0' + n);
	}
	return (len);
}

ssize_t	ft_puthex(unsigned long int n, char format)
{
	int		len;
	char	*base;
	char	buffer[20];
	int		i;

	len = 0;
	i = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		len += ft_putchar(base[0]);
		return (len);
	}
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}

ssize_t	ft_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("0x0"));
	len += ft_putstr("0x");
	return (len + ft_puthex(ptr, 'x'));
}
