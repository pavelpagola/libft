/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:37:41 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/11 23:33:07 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s || (char)c == 0)
		return ((char *)s);
	return (NULL);
}

static char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ans;

	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ans = malloc(l1 + l2 + 1);
	if (!ans)
	{
		free(s1);
		return (NULL);
	}
	ft_strcpy_gnl(ans, s1);
	ft_strcat_gnl(ans, s2);
	free(s1);
	return (ans);
}

static char	*get_line_gnl(char	**pile)
{
	char	*line;
	char	*l_pos;
	size_t	len;
	char	*rest;

	l_pos = ft_strchr_gnl(*pile, '\n');
	if (l_pos != NULL)
		len = l_pos - *pile + 1;
	else
		len = ft_strlen(*pile);
	line = ft_strndup_gnl(*pile, len);
	if (!line)
		return (NULL);
	rest = ft_strdup_gnl(*pile + len);
	free(*pile);
	*pile = rest;
	return (line);
}

static int	read_text_gnl(int fd, char **pile)
{
	char	*buffer;
	int		bytes;
	int		buffer_size;

	buffer_size = 1024;
	buffer = malloc(buffer_size + 1);
	if (!buffer)
		return (-1);
	while (1)
	{
		bytes = read(fd, buffer, buffer_size);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		*pile = ft_strjoin_gnl(*pile, buffer);
		if (*pile == NULL)
			return (free(buffer), -1);
		if (ft_strchr_gnl(*pile, '\n') != NULL)
			return (free(buffer), 1);
	}
	free(buffer);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*pile[1024] = {NULL};
	int			status;
	char		*line;

	ft_set_clean_gnl();
	if (fd == -1)
		ft_free_pile(pile);
	if (fd < 0)
		return (NULL);
	if (pile[fd] != NULL && ft_strchr_gnl(pile[fd], '\n') != NULL)
		return (get_line_gnl(&pile[fd]));
	status = read_text_gnl(fd, &pile[fd]);
	if (status == 1)
		return (get_line_gnl(&pile[fd]));
	else if (status == 0 && pile[fd] != NULL && *pile[fd] != '\0')
	{
		line = ft_strdup_gnl(pile[fd]);
		free(pile[fd]);
		pile[fd] = NULL;
		return (line);
	}
	if (pile[fd])
		free(pile[fd]);
	pile[fd] = NULL;
	return (NULL);
}
