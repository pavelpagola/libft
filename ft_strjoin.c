/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:03:18 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/03 19:21:08 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *)malloc(len1 + len2 + 1);
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, len1);
	ft_memcpy(joined_str + len1, s2, len2);
	joined_str[len1 + len2] = '\0';
	return (joined_str);
}
