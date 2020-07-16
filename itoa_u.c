/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/14 15:00:12 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"

static int	accuracy_u(unsigned long long int value, int base, s_data *data)
{
	int i;
	int	ii;

	i = 0;
	ii = 0;
	if (data->octotorp == 1)
		i = 2;
	while (value != 0 || (ii == 0 && data->accuracy != 0))
	{
		value = value / base;
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

void		itoa_u(unsigned long long int val, int base, s_data *data, char *s)
{
	int	i;

	if (data->type == 'u')
		data->octotorp = 0;
	if (data->type == 'p')
		data->octotorp = 1;
	if (accuracy_u(val, base, data) == 0)
	{
		data->arg[data->arg_len] = '\0';
		i = data->arg_len - 1;
		if (val == 0 && data->accuracy != 0)
			data->arg[i--] = '0';
		while (val != 0)
		{
			data->arg[i--] = s[val % base];
			val /= base;
		}
		while (i >= 0)
			data->arg[i--] = '0';
		if (data->octotorp == 1)
			data->arg[1] = s[16];
	}
}
