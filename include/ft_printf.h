/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:35:54 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/17 13:26:45 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF__
# define __FT_PRINTF__

/* ======  Include  ======= */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


/* ======  Macros  ======= */



/* ======  Prototype  ======= */

/* --- ft_printf.c --- */

int	ft_printf(const char *, ...);

#endif