/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/09/21 17:23:30 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny(t_stack **stack, t_meta *meta)
{
	while (!is_sorted(*stack))
	{
		if (gt((*stack)->content, (*stack)->next->content))
			sa(stack, meta);
		if (gt((*stack)->content, ft_lstlast(*stack)->content))
			rra(stack, meta);
		else if (!is_sorted(*stack) && ft_lstsize(*stack) == 3)
			ra(stack, meta);
	}
}
