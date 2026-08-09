/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:49:52 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 20:49:52 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex_rec(unsigned int n, char *base, int len)
{
	if (n > 15)
		len = put_hex_rec(n / 16, base, len);
	len += put_c(base[n % 16]);
	return (len);
}

int	put_x(unsigned int n, int flags, char specifier)
{
	char	*base;

	if (specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n && (flags >> 2 & 1))
		return (put_c('0') + put_c(specifier) + put_hex_rec(n, base, 0));
	return (put_hex_rec(n, base, 0));
}
