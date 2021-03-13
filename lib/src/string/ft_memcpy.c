/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:24:00 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/25 12:10:49 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if (dest == src)
		return (dest);
	cdest = dest;
	csrc = src;
	while (n--)
		cdest[n] = csrc[n];
	return (dest);
}
