/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:42:50 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/18 19:44:46 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strclean(char *str, char c)
{
	int			i;
	int			j;
	char		*ans;

	if (!str)
		return (NULL);
	if (!c)
		return (str);
	i = 0;
	j = 0;
	ans = ft_malloc(ft_strlen(str) + 1);
	while (str[i] && str[i + 1])
	{
		if (str[i] == c && str[i + 1] == c)
		{
			i++;
			continue ;
		}
		ans[j] = str[i];
		i++;
		j++;
	}
	if (str[i])
		ans[j] = str[i];
	return (ans);
}
