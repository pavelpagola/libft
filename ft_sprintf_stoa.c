/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_stoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:28:42 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/18 17:28:44 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stoa_sp(char *str)
{
	char	*ans;
	int		i;
	int		n;

	if (!str)
		return (ft_strndup_gnl("", 0));
	i = -1;
	n = ft_strlen(str);
	ans = malloc(n + 1);
	ans[n] = 0;
	while (++i < n)
		ans[i] = str[i];
	return (ans);
}

char	*ft_ptoa_sp(void *address)
{
	char				*ans;
	const char			*x_lower = "0123456789abcdef";
	unsigned long long	num;
	int					n;

	if (!address)
		return (ft_strndup_gnl("(nil)", 5));
	num = (unsigned long long)address;
	n = ft_digits_sp(num, 16);
	n += 2;
	ans = malloc(n + 1);
	ans[n] = 0;
	while (n--)
	{
		ans[n] = x_lower[num % 16];
		num = num / 16;
	}
	ans[0] = '0';
	ans[1] = 'x';
	return (ans);
}
