/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:48:50 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/09 09:30:16 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *new_dest;
	unsigned char *new_src;

	if (dest == src)
		return (dest);
	new_dest = (unsigned char*)dest;
	new_src = (unsigned char*)src;
	while (n--)
		*new_dest++ = *new_src++;
	return (dest);
}
