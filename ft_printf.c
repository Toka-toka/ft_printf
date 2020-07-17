/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:11:50 by sedric            #+#    #+#             */
/*   Updated: 2020/07/17 18:57:51 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	struct_clear(t_data *data)
{
	data->minus = 0;
	data->plus = 0;
	data->zero = 0;
	data->space = 0;
	data->octotorp = 0;
	data->error = 0;
	data->zero_type = 0;
	data->conversion = 0;
	data->width = 0;
	data->accuracy = -1;
	data->type = 0;
	data->arg = NULL;
	data->arg_len = 0;
}

int			ft_printf(const char *s, ...)
{
	t_data	data;

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
			struct_clear(&data);
			if (parsing(s, &data) == -1)
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
