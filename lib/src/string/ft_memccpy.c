/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:37:15 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/15 13:39:38 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2;

	s1 = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	while (n--)
	{
		*s1 = *s2;
		s1++;
		if (*s2 == (unsigned char)c)
			return (s1);
		s2++;
	}
	return (NULL);
}
