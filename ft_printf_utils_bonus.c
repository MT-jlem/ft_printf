/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:17:15 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/14 20:20:22 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag(const char *s, va_list arg, int i)
{
	va_list	dst;
	int		check;
	int		flag;

	flag = 0;
	va_copy (dst, arg);
	check = va_arg(dst, int);
	if ((s[i] == 'd' || s[i] == 'i') && check >= 0)
	{
		while (s[i--] != '%')
		{
			if (s[i] == '+')
				return (ft_putchar('+'));
			else if (s[i] == ' ')
				flag = 1;
		}
		if (flag == 1)
			return (ft_putchar(' '));
	}
	else if ((s[i] == 'x' || s[i] == 'X') && check != 0)
		return (sharp_flag(s, i));
	return (0);
}

int	sharp_flag(const char *s, int i)
{
	int	l;

	l = 0;
	if (s[i] == 'x')
	{
		while (s[i--] != '%')
			if (s[i] == '#')
				return (ft_putstr("0x"));
	}
	else if (s[i] == 'X')
	{
		while (s[i--] != '%')
			if (s[i] == '#')
				return (ft_putstr("0X"));
	}
	return (0);
}
