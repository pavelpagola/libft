/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:42:03 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/16 15:43:23 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	full_clean(t_list *new_node, t_list *ans, void (*del)(void *))
{
	del(new_node->content);
	free(new_node);
	ft_lstclear(&ans, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	ans = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			del(lst->content);
			ft_lstclear(&ans, del);
			return (NULL);
		}
		ft_lstadd_back(&ans, new_node);
		if (!ans)
		{
			full_clean(new_node, ans, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (ans);
}
