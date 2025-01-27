/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:41:05 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/16 14:41:09 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_gnl_order_free(void)
{
	get_next_line(-1);
}

void	ft_set_clean_gnl(void)
{
	static int	dfgdfg = 1;

	if (dfgdfg == 1)
	{
		dfgdfg = 0;
		atexit(ft_gnl_order_free);
	}
}
