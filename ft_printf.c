/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:41:36 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/30 20:40:13 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_s(char *str)
{
	int	ans;

	ans = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		ans += write(1, str++, 1);
	return (ans);
}

static int	ft_printf_x(unsigned int nbr, int up, unsigned long long n2, int p)
{
	static char	*x_upper = "0123456789ABCDEF";
	static char	*x_lower = "0123456789abcdef";
	int			len;

	len = 0;
	if (p)
	{
		if (n2 >= 16)
			len += ft_printf_x(0, 0, n2 / 16, 1);
		len += write(1, &x_lower[n2 % 16], 1);
		return (len);
	}
	if (nbr >= 16)
		len += ft_printf_x(nbr / 16, up, 0, 0);
	if (up)
		len += write(1, &x_upper[nbr % 16], 1);
	else
		len += write(1, &x_lower[nbr % 16], 1);
	return (len);
}

static int	ft_printf_ll(long long nbr)
{
	static char	*nums = "0123456789";
	int			len;

	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_printf_ll(nbr / 10);
	len += write(1, &nums[nbr % 10], 1);
	return (len);
}

static int	ft_choose_print(char format, va_list args)
{
	void		*addr;
	const int	f = format == 'X';

	if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
		return (write(1, &(char){(char)va_arg(args, int)}, 1));
	else if (format == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (format == 'p')
	{
		addr = va_arg(args, void *);
		if (!addr)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		return (ft_printf_x(0, 0, (unsigned long long)addr, 1) + 2);
	}
	else if (format == 'd' || format == 'i')
		return (ft_printf_ll(va_arg(args, int)));
	else if (format == 'u')
		return (ft_printf_ll(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printf_x(va_arg(args, ssize_t), f, 0, 0));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ans;
	int		i;

	i = 0;
	ans = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ans += ft_choose_print(format[i], args);
		}
		else
			ans += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (ans);
}
