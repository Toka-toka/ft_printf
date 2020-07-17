/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symb_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/17 18:54:31 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	width_set(t_data *data, char symbol)
{
	int i;

	i = data->width - data->arg_len;
	if (i > 0 && data->minus == 0)
	{
		if (data->zero_type == 1)
			symbol = '0';
		while (i > 0)
		{
			write(1, &symbol, 1);
			data->return_sum++;
			i--;
		}
	}
	putstr_pf(data);
	free(data->arg);
	if (i > 0)
	{
		while (i > 0)
		{
			write(1, &symbol, 1);
			data->return_sum++;
			i--;
		}
	}
}

void	string_arg(char *string, t_data *data)
{
	if (string == NULL)
	{
		data->arg_len = 6;
		string = "(null)";
	}
	else
		data->arg_len = ftp_strlen(string);
	if (data->accuracy != -1 && data->accuracy < data->arg_len)
		data->arg_len = data->accuracy;
	data->arg = malloc((data->arg_len + 1) * sizeof(char));
	if (data->arg == NULL)
		data->error = 1;
	else
		ftp_memcpy(data->arg, string, data->arg_len);
}

void	symb_arg(int symbol, t_data *data)
{
	data->arg = malloc(2 * sizeof(char));
	if (data->arg == NULL)
		data->error = 1;
	else
	{
		data->arg[0] = symbol;
		data->arg[1] = '\0';
		data->arg_len = 1;
	}
}
