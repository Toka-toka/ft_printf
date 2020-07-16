/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/16 23:21:20 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

static void		conversion_u(t_data *data, int base, char *symbols)
{
	unsigned long long int value;

	if (data->conversion == 0)
		value = va_arg(data->va, unsigned int);
	if (data->conversion == 1)
		value = va_arg(data->va, unsigned long int);
	if (data->conversion == 2)
		value = va_arg(data->va, unsigned long long int);
	if (data->conversion == 3)
		value = (short unsigned int)va_arg(data->va, unsigned int);
	if (data->conversion == 4)
		value = (unsigned char)va_arg(data->va, unsigned int);
	if (data->minus == 0 && data->accuracy == -1 && data->zero == 1)
		data->zero_type = 1;
	itoa_u(value, base, data, symbols);
}

static void		conversion_d(t_data *data)
{
	int long long value;

	if (data->conversion == 0)
		value = va_arg(data->va, int);
	if (data->conversion == 1)
		value = va_arg(data->va, long int);
	if (data->conversion == 2)
		value = va_arg(data->va, long long int);
	if (data->conversion == 3)
		value = (short int)va_arg(data->va, int);
	if (data->conversion == 4)
		value = (char)va_arg(data->va, int);
	if (data->minus == 0 && data->accuracy == -1 && data->zero == 1)
		data->zero_type = 1;
	itoa_10(value, data);
}

int				ft_get_arg(t_data *data)
{
	if (data->type == '%')
	{
		if (data->accuracy == -1 && data->zero == 1)
			data->zero_type = 1;
		ft_symb_arg('%', data);
	}
	if (data->type == 'c')
		ft_symb_arg(va_arg(data->va, int), data);
	if (data->type == 's')
		ft_string_arg(va_arg(data->va, char*), data);
	if (data->type == 'd' || data->type == 'i')
		conversion_d(data);
	if (data->type == 'u')
		conversion_u(data, 10, "0123456789abcdefx");
	if (data->type == 'x')
		conversion_u(data, 16, "0123456789abcdefx");
	if (data->type == 'X')
		conversion_u(data, 16, "0123456789ABCDEFX");
	if (data->type == 'p')
		itoa_u(va_arg(data->va, size_t), 16, data, "0123456789abcdefx");
	if (data->error == 1)
		return (-1);
	ft_width_set(data, ' ');
	return (0);
}
