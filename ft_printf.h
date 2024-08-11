/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:22:11 by rradin-m          #+#    #+#             */
/*   Updated: 2024/07/30 19:41:34 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

ssize_t	ft_printf(const char *format, ...);
ssize_t	ft_num(int n);
ssize_t	ft_puthex(unsigned long int n, char format);
ssize_t	ft_putnum_unsign(unsigned int n);
ssize_t	ft_pointer(unsigned long long ptr);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *str);

#endif