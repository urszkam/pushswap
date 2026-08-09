/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:49:52 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 20:49:52 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_nbr_rec(long nb, int len)
{
	if (nb < 0)
	{
		len += put_c('-');
		nb = -nb;
	}
	if (nb >= 10)
		len = put_nbr_rec(nb / 10, len);
	len += put_c(nb % 10 + '0');
	return (len);
}

int	put_n(long nb, int flags, char c)
{
	if (c != 'u' && nb >= 0 && ((flags & 1) || (flags >> 1 & 1)))
	{
		if (flags >> 1 & 1)
			return (put_c('+') + put_nbr_rec(nb, 0));
		return (put_c(' ') + put_nbr_rec(nb, 0));
	}
	return (put_nbr_rec(nb, 0));
}
