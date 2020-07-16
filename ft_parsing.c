/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:46:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/16 22:09:32 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	ft_conversion_pars(const char *s, int i, t_data *data)
{
	if (s[i] == 'l')
	{
		i++;
		if (s[i] == 'l')
		{
			data->conversion = 2;
			i++;
		}
		else
			data->conversion = 1;
	}
	else if (s[i] == 'h')
	{
		i++;
		if (s[i] == 'h')
		{
			data->conversion = 4;
			i++;
		}
		else
			data->conversion = 3;
	}
	return (i);
}

int	ft_accuracy_pars(const char *s, int i, t_data *data)
{
	data->accuracy = 0;
	if (s[i] == '*')
	{
		data->accuracy = va_arg(data->va, int);
		i++;
	}
	else
	{
		while (ft_strchr("0123456789", s[i]) != 0)
		{
			data->accuracy = data->accuracy * 10 + (s[i] - '0');
			i++;
		}
	}
	if (data->accuracy < -1)
		data->accuracy = -1;
	return (i);
}

int	ft_width_pars(const char *s, int i, t_data *data)
{
	if (s[i] == '*')
	{
		i++;
		data->width = va_arg(data->va, int);
		if (data->width < 0)
		{
			data->minus = 1;
			data->width = -data->width;
		}
	}
	else
	{
		while (ft_strchr("0123456789", s[i]) != 0)
		{
			data->width = data->width * 10 + (s[i] - '0');
			i++;
		}
	}
	if (data->width < 0)
		data->width = 0;
	return (i);
}

int	ft_flag_pars(const char *s, int i, t_data *data)
{
	i = data->index;
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
	if (data->plus == 1)
		data->space = 0;
	return (i);
}

int	ft_s_parsing(const char *s, t_data *data)
{
	int i;

	i = 0;
	i = ft_flag_pars(s, i, data);
	i = ft_width_pars(s, i, data);
	if (s[i] == '.')
	{
		i++;
		i = ft_accuracy_pars(s, i, data);
	}
	i = ft_conversion_pars(s, i, data);
	if (ft_strchr("cspdiuxX%", s[i]) != 0)
	{
		data->type = s[i];
		if (ft_get_arg(data) == -1)
			return (-1);
		data->index = i + 1;
	}
	else
	{
		write(1, "%", 1);
		data->return_sum++;
	}
	return (0);
}
