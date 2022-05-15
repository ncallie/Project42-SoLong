/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_descript.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:25:51 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/18 12:40:03 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_descript(va_list up, const char *input, int *print_s)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			check_flag(up, input[i], print_s);
		}
		else
			is_char(input[i], print_s);
		i++;
	}
}
