/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 06:58:45 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/15 17:43:08 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i++ < len)
		dup[i - 1] = s[i - 1];
	dup[i - 1] = '\0';
	return (dup);
}

char	*ft_strndup_gnl(const char *s, size_t n)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > n)
		len = n;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i++ < len)
		dup[i - 1] = s[i - 1];
	dup[i - 1] = '\0';
	return (dup);
}

char	*ft_strcpy_gnl(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat_gnl(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	if (!dest || !src)
		return (NULL);
	j = ft_strlen(dest);
	while (src[i])
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	ft_free_pile(char **pile)
{
	int	i;

	i = 2;
	while (++i < 1024)
	{
		if (pile[i] != NULL)
		{
			free(pile[i]);
			pile[i] = NULL;
		}
	}
}
