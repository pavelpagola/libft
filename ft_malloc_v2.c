/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:56:24 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/15 17:45:09 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_malloc_clean(void)
{
	static int	iusffdg = 1;

	if (iusffdg == 1)
	{
		iusffdg = 0;
		atexit(ft_free_all_malloc);
	}
}

static struct s_list	**ft_mallocs_logger(void)
{
	static struct s_list	*g_all_mallocs = NULL;

	return (&g_all_mallocs);
}

void	*ft_malloc(size_t size)
{
	void			*ptr;
	struct s_list	*new_node;
	struct s_list	**g_all_mallocs;

	g_all_mallocs = ft_mallocs_logger();
	ft_set_malloc_clean();
	ptr = malloc(size);
	ft_bzero(ptr, size);
	if (ptr == NULL)
		return (ptr);
	new_node = malloc(sizeof(struct s_list));
	if (new_node == NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_node->content = ptr;
	new_node->next = *g_all_mallocs;
	*g_all_mallocs = new_node;
	return (ptr);
}
/*
void	*ft_malloc(size_t size)
{
	void			*ptr;
	struct s_list	*new_node;
	struct s_list	**g_all_mallocs;

	g_all_mallocs = ft_mallocs_logger();
	ft_set_malloc_clean();
	ptr = malloc(size);
	ft_bzero(ptr, size);
	if (ptr != NULL)
	{
		new_node = malloc(sizeof(struct s_list));
		if (new_node != NULL)
		{
			new_node->content = ptr;
			new_node->next = *g_all_mallocs;
			*g_all_mallocs = new_node;
		}
		else
		{
			free(ptr);
			return (NULL);
		}
	}
	return (ptr);
}*/

void	ft_free(void *ptr)
{
	struct s_list	**current;
	struct s_list	*to_free;
	struct s_list	**g_all_mallocs;

	g_all_mallocs = ft_mallocs_logger();
	current = g_all_mallocs;
	while (*current)
	{
		if ((*current)->content == ptr)
		{
			free(ptr);
			ptr = NULL;
			to_free = *current;
			*current = (*current)->next;
			free(to_free);
			return ;
		}
		current = &(*current)->next;
	}
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_all_malloc(void)
{
	struct s_list	**current;
	struct s_list	*to_free;
	struct s_list	**g_all_mallocs;

	g_all_mallocs = ft_mallocs_logger();
	current = g_all_mallocs;
	while (*current)
	{
		if ((*current)->content != NULL)
			free((*current)->content);
		to_free = *current;
		*current = (*current)->next;
		free(to_free);
	}
	*g_all_mallocs = NULL;
}
