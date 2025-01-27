/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_ltoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:09:51 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/18 16:09:54 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits_sp(unsigned long long num, unsigned long long base)
{
	int	ans;

	ans = 1;
	while (num > (base - 1))
	{
		ans++;
		num = num / base;
	}
	return (ans);
}

char	*ft_ltoa_sp(long long num)
{
	char	*ans;
	int		n;
	int		neg;

	neg = 0;
	if (num < 0)
		neg = 1;
	if (num < 0)
		num = -num;
	n = ft_digits_sp(num, 10);
	n = n + neg;
	ans = malloc(n + 1);
	ans[n] = 0;
	while (n--)
	{
		ans[n] = (num % 10) + '0';
		num = num / 10;
	}
	if (neg == 1)
		ans[0] = '-';
	return (ans);
}

char	*ft_otoa_sp(unsigned long long num)
{
	char	*ans;
	int		n;

	n = ft_digits_sp(num, 8);
	ans = malloc(n + 1);
	ans[n] = 0;
	while (n--)
	{
		ans[n] = (num % 8) + '0';
		num = num / 8;
	}
	return (ans);
}

char	*ft_xtoa_sp(unsigned long long num, int upper)
{
	char		*ans;
	int			n;
	const char	*x_upper = "0123456789ABCDEF";
	const char	*x_lower = "0123456789abcdef";

	n = ft_digits_sp(num, 16);
	ans = malloc(n + 1);
	ans[n] = 0;
	while (n--)
	{
		if (upper == 1)
			ans[n] = x_upper[num % 16];
		else
			ans[n] = x_lower[num % 16];
		num = num / 16;
	}
	return (ans);
}

char	*ft_ctoa_sp(int i)
{
	char	*ans;

	ans = malloc(2);
	ans[1] = 0;
	ans[0] = (char)i;
	return (ans);
}
