/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:06:24 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/12 20:06:25 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(char *path_name)
{
	char	*ans;
	char	*line;
	int		fd;

	ans = NULL;
	fd = open(path_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ans = ft_strselfjoin(ans, line);
		free(line);
	}
	close(fd);
	return (ans);
}
