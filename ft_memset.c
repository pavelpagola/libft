/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:13:38 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/05 19:03:15 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;

	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
		*ptr++ = val;
	return (s);
}
//#include<stdio.h>
//#include<string.h>
/*
int     main(void)
{
        char    v[10];

        ft_memset(v, 42, 5);

        for (int i = 0; i < 10; ++i)
                printf("%d\n", v[i]);
        printf("ft_memset-> %p\n\n", ft_memset(v, 42, 5));



        memset(v, 21, 5);

        for (int i = 0; i < 10; ++i)
                printf("%d\n", v[i]);
        printf("Real memset-> %p\n", memset(v, 21, 5));
}
*/
