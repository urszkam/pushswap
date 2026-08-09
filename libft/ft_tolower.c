/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:49:52 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 20:58:39 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** converts the letter c to lower case, if possible
*/

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
