/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/05/26 00:01:46 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include "libftprintf.h"

int	ft_accuracy_set_16(int long long value, s_data *data)
{
    int i;
	int	ii;
    
	ii = 0;
	if (data->octotorp == 1 || data->type == 'p')
		i = 2;
	else i = 0;
    while (value != 0 || (ii == 0 && data->accuracy != 0))
    {	
		value = value / 16;
		ii++;
	}
	if (data->accuracy > ii)
	{
		data->accuracy -= ii;
		data->arg_len = i + ii + data->accuracy;
	}
	else data->arg_len = i + ii;
    data->arg = malloc((data->arg_len + 1) * sizeof(int));
	if (data->arg == NULL)
		data->error = 1;
	return (data->error);
}

void	ft_itoa_16(unsigned long long int value, s_data *data, char *digits)
{
    int	i;

    if (ft_accuracy_set_16(value, data) == 0)
	{
		data->arg[data->arg_len] = '\0';
		i = data->arg_len - 1;
		if (value == 0 && data->accuracy != 0)
			data->arg[i--] = '0';
		while (value != 0 )
		{
			data->arg[i--] = digits[value % 16];
			value /= 16;
		}
		while (data->accuracy-- > 0)
			data->arg[i--] = '0';
		if (data->octotorp == 1 || data->type == 'p')
		{
			data->arg[i--] = digits[16];
			data->arg[i--] = digits[0];
		}
 	}
}