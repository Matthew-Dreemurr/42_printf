/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:07:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/21 17:46:44 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
**   Return | Value
**   -------|------
**   TRUE   |  1
*/

int	dummy_arg(const char *str, t_data *data, va_list *args)
{
	(void)data;
	(void)args;
	(void)str;
#ifdef DEBUG_TRUE
	BM("dummy_arg");
	BR;
#endif
	return (TRUE);
}

/*
**   .
*/

int	dummy_flag(const char *str, t_data *data, va_list *args)
{
	(void)str;
	(void)data;
	(void)args;
#ifdef DEBUG_TRUE
	BM("dummy_flag");
	BR;
#endif
	return (FALSE);
}
