/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:47:39 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/05 17:55:47 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
