/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:24 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/22 12:59:29 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_str(char *str, int *print_s)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		is_char(str[i], print_s);
		i++;
	}
}
