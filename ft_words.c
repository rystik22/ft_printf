/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:06:04 by rradin-m          #+#    #+#             */
/*   Updated: 2024/07/31 18:30:59 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

ssize_t	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len] != '\0')
		ft_putchar (str[len++]);
	return (len);
}
