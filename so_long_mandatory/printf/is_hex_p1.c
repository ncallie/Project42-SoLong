/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex_p1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:16 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/23 17:32:01 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_hex_p1(unsigned int hex, int *print_s, int up_low)
{
	char			*str;
	unsigned int	size;

	size = 0;
	size = nbr_count(hex, 16);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return ;
	str[size--] = '\0';
	if (hex == 0)
	{
		is_char('0', print_s);
		free(str);
		return ;
	}
	while (hex != 0)
	{
		is_hex_hex(up_low, &str[size], &hex);
		size--;
	}
	is_str(str, print_s);
	free(str);
}
