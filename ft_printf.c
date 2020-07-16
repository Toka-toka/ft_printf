/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:11:50 by sedric            #+#    #+#             */
/*   Updated: 2020/07/14 22:11:53 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_struct_clear(s_data *data)
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
	data->conversion = 0;
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
			data.index++;
			ft_struct_clear(&data);
			if (ft_s_parsing(s, &data) == -1)
				return (-1);
		}
		else
		{
			write(1, &s[data.index], 1);
			data.index++;
			data.return_sum++;
		}
	}
	va_end(data.va);
	return (data.return_sum);
}