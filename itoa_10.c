/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/14 15:16:30 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"

static int	accuracy_10(int long long value, s_data *data, int i, int ii)
{
	if (data->plus == 1 || data->space == 1 || value < 0)
	{
		i = 1;
		if (data->accuracy == -1 && data->zero == 1)
		{
			data->accuracy = data->width - 1;
			data->width = 0;
		}
	}
	while (value != 0 || (ii == 0 && data->accuracy != 0))
	{
		value = value / 10;
		ii++;
	}
	if (data->accuracy > ii)
	{
		data->accuracy -= ii;
		data->arg_len = i + ii + data->accuracy;
	}
	else
		data->arg_len = i + ii;
	data->arg = malloc((data->arg_len + 1) * sizeof(int));
	if (data->arg == NULL)
		data->error = 1;
	return (data->error);
}

void		itoa_10(long long int value, s_data *data)
{
	unsigned int	new_value;
	int				i;

	if (accuracy_10(value, data, 0, 0) == 0)
	{
		data->arg[data->arg_len] = '\0';
		i = data->arg_len - 1;
		new_value = value >= 0 ? value : -value;
		while (new_value != 0)
		{
			data->arg[i--] = new_value % 10 + '0';
			new_value /= 10;
		}
		if (value == 0 && data->accuracy != 0)
			data->arg[i--] = '0';
		while (i >= 0)
			data->arg[i--] = '0';
		if (value < 0)
			data->arg[0] = '-';
		else if (data->space == 1)
			data->arg[0] = ' ';
		else if (data->plus == 1)
			data->arg[0] = '+';
	}
}
