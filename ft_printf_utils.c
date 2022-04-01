/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:04:18 by mjlem             #+#    #+#             */
/*   Updated: 2021/12/14 20:16:43 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long	n ;
	int		l;

	l = 0;
	n = nb;
	if (n < 0)
	{
		l += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		l += ft_putchar(n + '0');
	}
	else
	{
		l += ft_putnbr(n / 10);
		l += ft_putnbr(n % 10);
	}
	return (l);
}

int	ft_putunbr(unsigned int n)
{
	int	l;

	l = 0;
	if (n < 10)
	{
		l += ft_putchar(n + '0');
	}
	else
	{
		l += ft_putunbr(n / 10);
		l += ft_putunbr(n % 10);
	}
	return (l);
}

int	ft_puthex(unsigned long n)
{
	int		l;
	char	*base;

	l = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		l += ft_putchar(base[n]);
	}
	else
	{
		l += ft_puthex(n / 16);
		l += ft_puthex(n % 16);
	}
	return (l);
}

int	ft_putchex(unsigned int n)
{
	int		l;
	char	*base;

	l = 0;
	base = "0123456789ABCDEF";
	if (n < 16)
	{
		l += ft_putchar(base[n]);
	}
	else
	{
		l += ft_putchex(n / 16);
		l += ft_putchex(n % 16);
	}
	return (l);
}
