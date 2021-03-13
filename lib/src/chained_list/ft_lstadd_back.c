/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:21:04 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/19 15:28:45 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!(alst && new))
		return ;
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		*alst = new;
}
