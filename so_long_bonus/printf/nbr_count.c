/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:35 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/22 13:00:09 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	nbr_count(unsigned long long copy_p, int base)
{
	unsigned int	size;

	size = 0;
	if (copy_p == 0)
		size++;
	while (copy_p != 0)
	{
		copy_p = copy_p / base;
		size++;
	}
	return (size);
}
