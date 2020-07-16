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
	data->return_sum += data->arg_len;
	write(1, data->arg, data->arg_len);
//	printf("\ndata->arg_len_put_str = %d", data->arg_len);
}