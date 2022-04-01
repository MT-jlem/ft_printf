/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:11:03 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/14 20:14:10 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned long n);
int	ft_putchex(unsigned int n);
int	ft_putchar(int c);
int	convert(const char c, va_list arg);
int	is_format(const char c);
int	ft_flag(const char *s, va_list arg, int i);
int	sharp_flag(const char *s, int i);

#endif
