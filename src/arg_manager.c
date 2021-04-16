/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/16 17:46:50 by mhadad           ###   ########.fr       */
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
**
**   Return | Value
**   -------|------
**   TRUE   |  1
**   FALSE  |  0
*/

int	arg_c(const char *str, t_data *data, va_list *args)
{
	char	c;

#ifdef DEBUG_TRUE
BM("arg_c");
#endif

	(void)str;
	c = (char)va_arg(*args, int);
	print_arg_c(c, &(*data));
	data->skip++;
	return (TRUE);
}

/*
**   if `s` is null len = 6 (len_str("(null)"))
**   Return | Value
**   -------|------
**   TRUE   |  1
*/

int	arg_s(const char *str, t_data *data, va_list *args)
{
	const char	*s;

#ifdef DEBUG_TRUE
BM("arg_s");
#endif

	(void)str;
	s = (const char *)va_arg(*args, const char *);
	if (!s)
	{
		print_arg_s(STR_NULL, &(*data));
		data->skip++;
		return (TRUE);
	}
	print_arg_s(s, &(*data));
	data->skip++;
	return (TRUE);
}

/*
**
*/

int	arg_d(const char *str, t_data *data, va_list *args)
{
	int nbr;

	(void)str;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (int)va_arg(*args, int);
	(void)nbr;
	return (TRUE);
}

/*
**
*/

int	arg_u(const char *str, t_data *data, va_list *args)
{
	unsigned int	nbr;

	(void)str;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (unsigned int)va_arg(*args, unsigned int);
	(void)nbr;
	return (TRUE);
}

/*
**
*/

int	arg_p(const char *str, t_data *data, va_list *args)
{
	void	*ptr;
	char	*s;

	(void)str;
	ptr = (void*)va_arg(*args, void *);
	s = ulongtohex((unsigned long)ptr, &(*data));
	if (!s)
		return (ERR);
	free(s);
	data->skip++;
	return (TRUE);
}

/*
**
*/

int	arg_x(const char *str, t_data *data, va_list *args)
{
	unsigned long	nbr;
	char			*s;

	(void)str;
	nbr = (unsigned long)va_arg(*args, unsigned long);
	s = ulongtohex(nbr, &(*data));
	if (!s)
		return (ERR);
#ifdef DEBUG_TRUE
BM("arg_x");
DE(nbr);
D_STR_DETAILS(s);
#endif
	print_arg_x(s, &(*data));
	free(s);
	data->skip++;
	return (TRUE);
}

/*
**
*/

int	arg_x_up(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->x_up++;
	if (!(arg_x(NULL, &(*data), &(*args))))
		return (FALSE);
	return (TRUE);
}