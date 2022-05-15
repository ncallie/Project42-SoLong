/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:25:56 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/27 14:12:28 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(va_list up, char input, int *print_s)
{
	if (input == 'c')
		is_char(va_arg(up, int), print_s);
	else if (input == 's')
		is_str(va_arg(up, char *), print_s);
	else if (input == 'p')
		is_pointer(va_arg(up, void *), print_s);
	else if (input == 'd')
		is_number(va_arg(up, int), print_s);
	else if (input == 'i')
		is_number(va_arg(up, int), print_s);
	else if (input == 'u')
		is_unsig_number(va_arg(up, unsigned int), print_s);
	else if (input == 'x')
		is_hex_p1(va_arg(up, unsigned long long), print_s, 0);
	else if (input == 'X')
		is_hex_p1(va_arg(up, unsigned long long), print_s, 1);
	else if (input == '%')
		is_char('%', print_s);
	else
		is_char(input, print_s);
}
