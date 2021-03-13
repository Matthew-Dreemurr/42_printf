/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:22:19 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/26 14:30:23 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(buff = malloc(sizeof(buff) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_bzero(buff, len_s1 + len_s2 + 1);
	ft_strlcat(buff, s1, len_s1 + 1);
	ft_strlcat(buff, s2, len_s1 + len_s2 + 1);
	return (buff);
}
