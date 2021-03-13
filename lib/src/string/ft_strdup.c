/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:42:51 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/15 13:39:38 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	if (!(s2 = (malloc(sizeof(char) * len + 1))))
		return (NULL);
	ft_memcpy(s2, s, len + 1);
	return (s2);
}
