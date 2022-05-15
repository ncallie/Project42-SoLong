/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:40:58 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/18 17:51:52 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_hex_hex(int up_low, char *str_sym, unsigned int *copy_p)
{
	if (*copy_p % 16 < 10)
		str_sym[0] = *copy_p % 16 + 48;
	else if (up_low == 0)
		str_sym[0] = *copy_p % 16 + 87;
	else if (up_low == 1)
		str_sym[0] = *copy_p % 16 + 55;
	*copy_p = *copy_p / 16;
}
