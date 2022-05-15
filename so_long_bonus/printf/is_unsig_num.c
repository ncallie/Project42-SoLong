/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unsig_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:26 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/23 17:39:44 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_unsig_number(unsigned int num, int *print_s)
{
	num = (unsigned int)(4294967295 + 1 + num);
	if (num >= 10)
	{
		is_unsig_number(num / 10, print_s);
		is_unsig_number(num % 10, print_s);
	}
	else
		is_char(num + 48, print_s);
}
