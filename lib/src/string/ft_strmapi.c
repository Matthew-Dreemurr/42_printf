/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:23:17 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/26 14:35:44 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*buff;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(buff = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(buff, len + 1);
	while (i < len)
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	return (buff);
}
