/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:49:18 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/16 15:50:04 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strselfjoin_sp(char *self, const char *s2)
{
	char	*ans;

	if (!self)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (self);
	ans = malloc(ft_strlen(self) + ft_strlen(s2) + 1);
	if (!ans)
	{
		free(self);
		return (NULL);
	}
	ft_strcpy_gnl(ans, self);
	ft_strcat_gnl(ans, s2);
	free(self);
	return (ans);
}

static void	ft_flush_buffer_sp(char **ans, char **buffer, int *j)
{
	*ans = ft_strselfjoin_sp(*ans, *buffer);
	free(*buffer);
	*buffer = NULL;
	*buffer = malloc(1024);
	ft_bzero(*buffer, 1024);
	*j = 0;
}

static void	ft_sprintf_init(int *i, char **buffer, char **ans, int *j)
{
	*ans = NULL;
	*buffer = malloc(1024);
	ft_bzero(*buffer, 1024);
	*i = 0;
	*j = 0;
}

char	*ft_sprintf_main(const char *format, va_list args)
{
	char	*ans;
	char	*buffer;
	int		i;
	int		j;

	ft_sprintf_init(&i, &buffer, &ans, &j);
	while (format[i] && ((unsigned int)i < ft_strlen(format)))
	{
		if (j == 1022)
			ft_flush_buffer_sp(&ans, &buffer, &j);
		if (format[i] != '%')
		{
			buffer[j] = format[i];
			j++;
			i++;
			continue ;
		}
		ft_flush_buffer_sp(&ans, &buffer, &j);
		free(buffer);
		buffer = ft_special_sprintf(&format[i + 1], args, &i);
		ft_flush_buffer_sp(&ans, &buffer, &j);
	}
	ft_flush_buffer_sp(&ans, &buffer, &j);
	free(buffer);
	return (ans);
}
