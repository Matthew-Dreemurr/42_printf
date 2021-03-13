/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:52:30 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/29 14:29:59 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = NULL;
	if (!lst)
		return ;
	tmp = (*lst);
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
