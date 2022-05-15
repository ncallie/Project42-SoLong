/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:26:03 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/23 17:41:27 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(const char *input, ...);
void			check_flag(va_list up, char input, int *print_s);
void			is_char(char c, int *print_s);
void			check_descript(va_list up, const char *input, int *print_s);
void			is_pointer(void *p, int *print_s);
void			is_str(char *str, int *print_s);
unsigned int	nbr_count(unsigned long long copy_p, int base);
void			put_pointer(void *p, int *print_s);
void			is_number(int num, int *print_s);
void			is_unsig_number(unsigned int num, int *print_s);
void			is_hex_p1(unsigned int hex, int *print_s, int up_low);
void			is_hex_hex(int up_low, char *str_sym, unsigned int *copy_p);
void			is_hex_point(int up_low, char *str_sym,
					unsigned long long *copy_p);

#endif
