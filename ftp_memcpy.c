/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedric <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:13:04 by sedric            #+#    #+#             */
/*   Updated: 2020/07/17 18:57:03 by sedric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ftp_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_point;
	unsigned char *src_point;

	dest_point = (unsigned char*)dest;
	src_point = (unsigned char*)src;
	if (dest_point == NULL && src_point == NULL)
		return (dest);
	while (n > 0)
	{
		*dest_point++ = *src_point++;
		n--;
	}
	return (dest);
}
