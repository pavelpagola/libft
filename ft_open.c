/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:00:29 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/22 17:00:47 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_close_all(void)
{
	int	i;

	i = 2;
	while (++i < 1024)
		close(i);
}

static void	ft_set_close(void)
{
	static int	i = 1;

	if (i == 1)
	{
		i = 0;
		atexit(ft_close_all);
	}
}

int	ft_open(char *filename, int mode)
{
	int	fd;

	ft_set_close();
	if (mode == 0)
		fd = open(filename, O_RDONLY);
	else if (mode == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (mode == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
	{
		perror("Invalid mode");
		exit(1);
	}
	if (fd == -1)
	{
		perror("File error");
		exit(1);
	}
	return (fd);
}
