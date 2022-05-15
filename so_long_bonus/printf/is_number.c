/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:19 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/22 18:07:46 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_number(int num, int *print_s)
{
	if (num == -2147483648)
	{
		is_char('-', print_s);
		is_char('2', print_s);
		num = 147483648;
	}
	else if (num < 0)
	{
		is_char('-', print_s);
		num = -num;
	}
	if (num >= 10)
	{
		is_number (num / 10, print_s);
		is_number (num % 10, print_s);
	}
	else
		is_char (num + 48, print_s);
}
