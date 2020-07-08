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

#include "libftprintf.h"

char		*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	number;

	i = n > 0 ? 0 : 1;
	number = n >= 0 ? n : -n;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[0] = number != 0 ? '-' : '0';
	str[i] = '\0';
	while (number != 0)
	{
		str[--i] = number % 10 + 48;
		number = number / 10;
	}
	return (str);
}
