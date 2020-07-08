/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/02 17:44:48 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_get_arg(s_data *data)
{
	if (data->type == '%')
		ft_symb_arg('%', data);
	if (data->type == 'c')
		ft_symb_arg(va_arg(data->va, int), data);
	if (data->type == 's')
		ft_string_arg(va_arg(data->va, char*), data); 
/*  if (type == 'd' || type == 'i')
		ft_itoa(va_arg(data->va, int));
	if (type == 'p')
		write(1, "type p\n", 7);
	if (type == 'u')
		write(1, "type u\n", 7);
	if (type == 'x')
		write(1, "type x\n", 7);
	if (type == 'X')
		write(1, "type X\n", 7); */
	if (data->error == 1) 
		return (-1);
	else ft_width_set(data);
	printf ("\ndata->data->index = %d", data->index);
	printf ("\ndata->data->minus = %d", data->minus);
	printf ("\ndata->data->plus = %d", data->plus);
	printf ("\ndata->ddata->zero = %d", data->zero);
	printf ("\ndata->space = %d", data->space);
	printf ("\ndata->octotorp = %d", data->space);
	printf ("\ndata->width = %d", data->width);
	printf ("\ndata->accuracy = %d", data->accuracy);
	printf ("\ndata->type = %c", data->type);
	printf ("\ndata->arg_len = %d", data->arg_len);
	printf ("\ndata->return_sum = %d", data->return_sum);
	printf ("\ndata->error = %d", data->error);
	return (0);
}

void		struct_clear(s_data *data)
{
	data->minus = 0;
	data->plus = 0;
	data->zero = 0;
	data->space = 0;
	data->octotorp = 0;
	data->width = 0;
	data->accuracy = -1;
	data->type = 0;
	data->arg = NULL;
	data->arg_len = 0;
	data->error = 0;
}
int		parsing (const char *s, s_data *data)
{
	char	*string;
	int		index_plus;
	
	struct_clear(data);
	index_plus = data->index;
	while (ft_strchr("-0# +", s[index_plus]) != 0)
	{
		if (s[index_plus] == '-')
			data->minus = 1;
		if (s[index_plus] == '+')
			data->plus = 1;
		if (s[index_plus] == '0')
			data->zero = 1;
		if (s[index_plus] == ' ')
			data->space = 1;
		if (s[index_plus] == '#')
			data->octotorp = 1;
		index_plus++;
	}
	while (ft_strchr("0123456789", s[index_plus]) != 0)
	{
		data->width = data->width * 10 + (s[index_plus] - '0');
		index_plus++;
	}
	if (s[index_plus] == '.')
	{
		data->accuracy = 0;
		index_plus++;
		while (ft_strchr("0123456789", s[index_plus]) != 0)
		{
			data->accuracy = data->accuracy * 10 + (s[index_plus] - '0');
			index_plus++;
		}
	}
	if (ft_strchr("cspdiuxX%", s[index_plus]) != 0)
	{
		data->index = index_plus + 1;
		data->type = s[index_plus];
		if (ft_get_arg(data) == -1)
			return (-1);
	}
	else write (1, "%", 1);
	return (0);
}

int		ft_printf(const char *s, ...)
{
	s_data	data;

	data.index = 0;
	data.return_sum = 0;
	va_start(data.va, s);
	while (s[data.index] != '\0')
	{
		if (s[data.index] == '%')
		{
			data.index++;
			if (parsing(s, &data) == -1)
				return (-1);
		}	
		else 
		{
			write(1, &s[data.index], 1);
			data.index++;
			data.return_sum++;
		}
//		printf("\nindex = %d, return_sum = %d\n", data.index, data.return_sum);
	}
	va_end(data.va);
	return (data.return_sum);
}
