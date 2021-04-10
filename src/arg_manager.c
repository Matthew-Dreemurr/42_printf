/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/10 17:29:00 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

int	dummy_arg(const char *str, t_data *data, va_list *args)
{
	(void)data;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int	arg_c(const char *str, t_data *data, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (TRUE);
}

/*
**   if `s` is null len = 6 (len_str("(null)"))
*/

int	arg_s(const char *str, t_data *data, va_list *args)
{
	const char	*s;
	size_t		len;

	(void)str;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	s = (const char *)va_arg(*args, const char *);
	return (TRUE);
}

/*
**
*/

int	arg_d(const char *str, t_data *data, va_list *args)
{
	size_t len;
	int nbr;

	(void)str;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (int)va_arg(*args, int);
	return (TRUE);
}

/*
**
*/

int	arg_u(const char *str, t_data *data, va_list *args)
{
	size_t			len;
	unsigned int	nbr;

	(void)str;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (unsigned int)va_arg(*args, unsigned int);
	return (TRUE);
}

/*
**
*/

int	arg_p(const char *str, t_data *data, va_list *args)
{
	void	*ptr;
	char	*s;
	size_t	len;

	(void)str;
	data->skip++;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	ptr = (void*)va_arg(*args, void *);
	s = ulongtohex((unsigned long)ptr, &(*data));
	if (!s)
		return (ERR);
	free(s);
	return (TRUE);
}

/*
**
*/

int	arg_x(const char *str, t_data *data, va_list *args)
{
	unsigned long	nbr;
	char			*s;
	size_t			len;

	(void)str;
	data->skip++;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (unsigned long)va_arg(*args, unsigned long);
	s = ulongtohex(nbr, &(*data));
	if (!s)
		return (ERR);
	free(s);
	return (TRUE);
}

/*
**
*/

int	arg_x_up(const char *str, t_data *data, va_list *args)
{
	data->x_up++;
	if (!(arg_x(NULL, &(*data), &(*args))))
		return (FALSE);
	return (TRUE);
}