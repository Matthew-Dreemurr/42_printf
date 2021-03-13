/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:51:37 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/25 12:17:31 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cpy_s;

	cpy_s = (char *)s;
	while (*cpy_s)
	{
		if (*cpy_s == (char)c)
			return (cpy_s);
		cpy_s++;
	}
	if (c)
		return (NULL);
	else
		return (cpy_s);
}
