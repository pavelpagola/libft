/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:06:36 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/19 20:06:41 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_occurrences(char *str, char *old)
{
	int		i;
	int		count;
	int		old_len;

	i = 0;
	count = 0;
	old_len = ft_strlen(old);
	while (str[i])
	{
		if (ft_strncmp(&str[i], old, old_len) == 0)
		{
			count++;
			i += old_len;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_allocate_result(char *str, int count, char *old, char *new)
{
	int		str_len;

	str_len = ft_strlen(str);
	return (ft_malloc(str_len + count * (ft_strlen(new) - ft_strlen(old)) + 1));
}

static int	ft_copy_replacement(char *str, char *result, char *old, char *new)
{
	int		old_len;
	int		result_len;

	old_len = ft_strlen(old);
	result_len = ft_strlen(result);
	if (ft_strncmp(str, old, old_len) == 0)
	{
		ft_strcpy_gnl(&result[result_len], new);
		return (old_len);
	}
	else
		result[result_len] = str[0];
	return (1);
}

static int	ft_strreplace_err(char *str, char *old, char *new)
{
	if (!str || !old || !new)
		return (1);
	if (ft_strlen(str) == 0 || ft_strlen(old) == 0)
		return (1);
	return (0);
}

char	*ft_strreplace(char *str, char *old, char *new)
{
	int		i;
	int		count;
	char	*result;

	if (ft_strreplace_err(str, old, new) == 1)
		return (ft_strdup(str));
	count = ft_count_occurrences(str, old);
	result = ft_allocate_result(str, count, old, new);
	if (!result)
		return (ft_strdup(str));
	i = 0;
	while (str[i])
		i += ft_copy_replacement(&str[i], result, old, new);
	return (result);
}
