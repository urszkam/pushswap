/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:49:52 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 21:02:08 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcpy() function copies n bytes from memory area src to
** memory area dest. The memory areas must not overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (n--)
		*(dest_ptr++) = *(src_ptr++);
	return (dest);
}
