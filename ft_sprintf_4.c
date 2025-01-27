/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:24:36 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/18 15:25:01 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//"%diuoxXcsp fFeEgGaA \0"

static char	*ft_compute_base_rest_sp(double num, char type)
{
	if (num || type)
		return (ft_strndup_gnl("", 0));
	return (ft_strndup_gnl("", 0));
}

static char	*ft_compute_base_sp(char type, va_list args)
{
	if (type == '%')
		return (ft_strndup_gnl("%", 1));
	if (type == 'u')
		return (ft_ltoa_sp(va_arg(args, unsigned int)));
	if (type == 'i' || type == 'd')
		return (ft_ltoa_sp(va_arg(args, int)));
	if (type == 'o')
		return (ft_otoa_sp(va_arg(args, unsigned long long)));
	if (type == 'x' || type == 'X')
		return (ft_xtoa_sp(va_arg(args, unsigned long long), type == 'X'));
	if (type == 'c')
		return (ft_ctoa_sp(va_arg(args, int)));
	if (type == 's')
		return (ft_stoa_sp(va_arg(args, char *)));
	if (type == 'p')
		return (ft_ptoa_sp(va_arg(args, void *)));
	return (ft_compute_base_rest_sp(va_arg(args, double), type));
}

static char	*ft_compute_flags_rest_sp(char *base, char *flags, char type)
{
	if (flags || type)
		return (base);
	return (base);
}
/*
static char	*ft_compute_flags_sp(char *base, char *flags, char type)
{
	if (type == 'u')
		return (ft_uflag_sp(base, flags));
	if (type == 'i' || type == 'd')
		return (ft_uflag_sp(base, flags));
	if (type == 'o')
		return (ft_uflag_sp(base, flags));
	if (type == 'x' || type == 'X')
		return (ft_uflag_sp(base, flags));
	if (type == 'c')
		return (ft_uflag_sp(base, flags));
	if (type == 's')
		return (ft_uflag_sp(base, flags));
	if (type == 'p')
		return (ft_uflag_sp(base, flags));
	return (ft_compute_flags_rest_sp(base, flags, type));
}*/

static char	*ft_compute_flags_sp(char *base, char *flags, char type)
{
	return (ft_compute_flags_rest_sp(base, flags, type));
}

char	*ft_compute_sp(char type, char *flags, va_list args)
{
	char	*base;

	base = ft_compute_base_sp(type, args);
	if (ft_strlen(flags) != 0)
		return (ft_compute_flags_sp(base, flags, type));
	return (base);
}
