/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:13:04 by sedric            #+#    #+#             */
/*   Updated: 2020/05/25 20:49:11 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_strchr(const char *s, int c)
{
	char	*str;
	char	symbol;
	size_t	i;

	i = 0;
	symbol = (char)c;
	str = (char*)s;
	while (str[i] != '\0')
	{
		if (str[i] == symbol)
			return (str + i);
		i++;
	}
	return (c == '\0' ? str + i : NULL);
}
