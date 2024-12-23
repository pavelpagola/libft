/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:19:15 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/05 19:14:38 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!dst && !size)
		return (s_len);
	d_len = ft_strlen(dst);
	if (d_len >= size)
		return (s_len + size);
	else
		size -= d_len;
	ft_strlcpy(dst + d_len, src, size);
	return (d_len + s_len);
}
