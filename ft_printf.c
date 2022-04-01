/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:56:33 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/14 20:10:54 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	convert(const char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		count += ft_putunbr(va_arg(arg, unsigned int));
	if (c == 'x')
		count += ft_puthex(va_arg(arg, unsigned int));
	if (c == 'X')
		count += ft_putchex(va_arg(arg, unsigned int));
	if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_puthex(va_arg(arg, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' )
		{
			i++;
			while ((s[i] == '+' || s[i] == ' ' || s[i] == '#') && s[i])
				i++;
			count += ft_flag(s, arg, i);
			count += convert(s[i++], arg);
		}
		else
			count += ft_putchar(s[i++]);
	}
	va_end(arg);
	return (count);
}
