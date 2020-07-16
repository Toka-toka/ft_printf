/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:00:47 by sedric            #+#    #+#             */
/*   Updated: 2020/07/16 23:57:35 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_putstr_pf(t_data *data)
{
	if (data->arg != NULL)
	{
		data->return_sum += data->arg_len;
		write(1, data->arg, data->arg_len);
	}
}
