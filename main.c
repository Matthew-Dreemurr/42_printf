/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:14:09 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/18 17:15:53 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "include/debug_utils.h"
#include "include/wraloc.h"
#define ARG1 "test%%123\n"

int	main(void)
{
	printf("pritf ret: [%d]\n", printf(ARG1));
	puts("\n");
	printf("ft_pritf ret: [%d]\n", ft_printf(ARG1));
	return (0);
}
