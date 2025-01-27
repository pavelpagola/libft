/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:02:17 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/16 18:02:43 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_valid_flag_sp(char type, char *flags)
{
	if (ft_strlen(flags) == 0 || type == 'c')
		return (1);
	return (0);
}

char	*ft_special_sprintf(const char *format, va_list args, int *i)
{
	int			f_l;
	const char	*types = "diuoxXfFeEgGaAcsp%\0";
	char		type;
	char		*flags;
	char		*ans;

	f_l = 0;
	while (format[f_l] && (ft_isalpha(format[f_l]) == 0) && format[f_l] != '%')
		f_l++;
	*i += f_l + 2;
	if ((format[f_l] == '\0') || (ft_strchr(types, format[f_l]) == NULL))
		return (NULL);
	flags = ft_strndup_gnl(format, f_l);
	type = format[f_l];
	if (ft_check_valid_flag_sp(type, flags) == 0)
	{
		free(flags);
		flags = ft_strndup_gnl("", 0);
	}
	ans = ft_compute_sp(type, flags, args);
	free(flags);
	return (ans);
}
