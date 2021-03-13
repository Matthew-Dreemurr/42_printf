/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:39:30 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/06 16:25:59 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**md_cpy(char const *s, char c, char **ret, size_t word)
{
	size_t	index;
	size_t	len;
	size_t	i;

	i = 0;
	index = 0;
	while (s[i] && index < word)
	{
		len = 0;
		if (s[i] != c)
		{
			while (s[i + len] != c && s[i + len])
				len++;
			if (!(ret[index] = ft_substr(s, i, len)))
				return (NULL);
			index++;
		}
		i += len + 1;
	}
	return (ret);
}

static size_t			md_wordcount(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			word++;
		}
		if (*s)
			s++;
	}
	return (word);
}

char					**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	word;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	word = md_wordcount(s, c);
	if (!(ret = malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	ft_bzero(ret, sizeof(char *) * (word + 1));
	if (!(ret = md_cpy(s, c, ret, word)))
	{
		while (ret[i])
		{
			free(ret[i]);
			i++;
		}
		free(ret);
		return (NULL);
	}
	return (ret);
}
