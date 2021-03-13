/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:57:49 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/29 17:28:08 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	md_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	b_len;
	size_t	l_len;

	b_len = md_strlen(big);
	l_len = md_strlen(little);
	ret = (char *)big;
	i = 0;
	if (!l_len)
		return (ret);
	if (b_len < l_len || !b_len)
		return (NULL);
	while (*ret && l_len <= len)
	{
		if (!ft_strncmp(big + i, little, l_len))
			return (ret);
		ret++;
		len--;
		i++;
	}
	return (NULL);
}
