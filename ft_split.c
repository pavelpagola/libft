/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:06:53 by ppagola-          #+#    #+#             */
/*   Updated: 2024/12/16 15:19:55 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*get_next_word(char const **s, char c)
{
	char	*word;
	int		len;

	while (**s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = (char *)ft_malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, *s, len + 1);
	*s += len;
	return (word);
}

void	ft_free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		ft_free(result[i]);
		i++;
	}
	ft_free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	result = (char **)ft_malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			ft_free_split(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
