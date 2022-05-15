/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:25:59 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/18 12:39:41 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	up;
	int		print_s;

	print_s = 0;
	if (input == '\0')
		return (print_s);
	va_start (up, input);
	check_descript(up, input, &print_s);
	va_end (up);
	return (print_s);
}
