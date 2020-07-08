/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:00:47 by sedric            #+#    #+#             */
/*   Updated: 2020/05/25 12:10:09 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_putstr_pf(s_data *data)
{
	data->return_sum = data->arg_len;
	write(1, data->arg, data->arg_len);
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
}