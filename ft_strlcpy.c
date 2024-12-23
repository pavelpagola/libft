/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:12:52 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/05 18:57:08 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (!src || !dst || !size)
		return (i);
	while (--size && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
