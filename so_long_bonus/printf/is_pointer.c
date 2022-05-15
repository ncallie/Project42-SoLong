/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:21 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/18 12:40:43 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_pointer(void *p, int *print_s)
{
	unsigned long long	copy_p;
	unsigned int		size;
	char				*str;

	size = 0;
	copy_p = (unsigned long long)p;
	size = nbr_count(copy_p, 16);
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return ;
	str[size--] = '\0';
	if (copy_p == 0)
	{
		is_str("0x0", print_s);
		free(str);
		return ;
	}
	while (copy_p != 0)
	{
		is_hex_point(0, &str[size], &copy_p);
		size--;
	}
	is_str("0x", print_s);
	is_str(str, print_s);
	free(str);
}
