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
	if (data->type == 'u')
		ft_itoa_10(va_arg(data->va, unsigned int), data);
	if (data->type == 'd' || data->type == 'i')
		ft_itoa_10(va_arg(data->va, int), data);
	if (data->type == 'p')
		ft_itoa_16(va_arg(data->va, unsigned long long int), data, "0123456789abcdefx");
	if (data->type == 'x')
		ft_itoa_16(va_arg(data->va, unsigned int), data, "0123456789abcdefx");
	if (data->type == 'X')
		ft_itoa_16(va_arg(data->va, unsigned int), data, "0123456789ABCDEFX");
	if (data->error == 1) 
		return (-1);
	else ft_width_set(data, ' ');
	return (0);
}

/*	printf ("\ndata->data->index = %d", data->index);
	printf ("\ndata->data->minus = %d", data->minus);
	printf ("\ndata->data->plus = %d", data->plus);
	printf ("\ndata->ddata->zero = %d", data->zero);
	printf ("\ndata->space = %d", data->space);
	printf ("\ndata->octotorp = %d", data->space);
	printf ("\ndata->width = %d", data->width);
	printf ("\ndata->accuracy = %d", data->accuracy);
	printf ("\ndata->arg_len = %d", data->arg_len);
	printf ("\ndata->return_sum = %d", data->return_sum);
	printf ("\ndata->error = %d", data->error); */

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
	int		i;
	
	struct_clear(data);
	i = data->index + 1;
	while (ft_strchr("-0# +", s[i]) != 0)
	{
		if (s[i] == '-')
			data->minus = 1;
		if (s[i] == '+')
			data->plus = 1;
		if (s[i] == '0')
			data->zero = 1;
		if (s[i] == ' ')
			data->space = 1;
		if (s[i] == '#')
			data->octotorp = 1;
		i++;
	}
	while (ft_strchr("0123456789", s[i]) != 0)
	{
		data->width = data->width * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
	{
		data->accuracy = 0;
		i++;
		while (ft_strchr("0123456789", s[i]) != 0)
		{
			data->accuracy = data->accuracy * 10 + (s[i] - '0');
			i++;
		}
	}
	if (ft_strchr("cspdiuxX%", s[i]) != 0)
	{
		data->index = i + 1;
		data->type = s[i];
		if (ft_get_arg(data) == -1)
			return (-1);
	}
	else 
	{
		write (1, "%", 1);
		data->index++;
		data->return_sum++;
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	s_data	data;

	data.index = 0;
	data.return_sum = 0;
	va_start(data.va, s);
	if (s == NULL)
		return (-1);
	while (s[data.index] != '\0')
	{
		if (s[data.index] == '%')
		{
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
