/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:46:05 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/16 17:46:10 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sprintf(const char *format, ...)
{
	va_list	args;
	char	*ans;

	va_start(args, format);
	ans = ft_sprintf_main(format, args);
	va_end(args);
	ans = ft_strselfjoin(ans, "");
	return (ans);
}

int	ft_printf2(const char *format, ...)
{
	va_list	args;
	char	*ans;
	int		n;

	va_start(args, format);
	ans = ft_sprintf_main(format, args);
	va_end(args);
	n = write(1, ans, ft_strlen(ans));
	free(ans);
	return (n);
}
