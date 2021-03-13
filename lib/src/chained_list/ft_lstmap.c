/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:24:27 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/26 15:27:36 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list		*ret;

	if (!lst)
		return (NULL);
	if (!(ret = ft_lstnew(f(lst->content))))
		return (NULL);
	if (lst->next)
	{
		if (!(ret->next = ft_lstmap(lst->next, f, d)))
		{
			d(ret);
			return (NULL);
		}
	}
	else
		ret->next = NULL;
	return (ret);
}
