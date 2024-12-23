/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:13:22 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/04 19:23:04 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = ft_num_len(n);
	str = (char *)malloc(len + 1 + neg);
	if (!str)
		return (NULL);
	str[len + neg] = '\0';
	if (neg)
		str[0] = '-';
	while (len + neg > neg)
	{
		str[--len + neg] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
