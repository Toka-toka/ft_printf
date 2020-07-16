/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:13:04 by sedric            #+#    #+#             */
/*   Updated: 2020/05/25 20:48:45 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str_point;
	unsigned char	symbol;

	str_point = (unsigned char*)s;
	symbol = c;
	while (n > 0)
	{
		*str_point++ = symbol;
		n--;
	}
	return (s);
}
