/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lt(void *num1, void *num2)
{
	return (*(int *)num1 < *(int *)num2);
}

int	gt(void *num1, void *num2)
{
	return (*(int *)num1 > *(int *)num2);
}

int	eq(void *num1, void *num2)
{
	return (*(int *)num1 == *(int *)num2);
}

int	min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
