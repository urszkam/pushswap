/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small2.c                                      :+:      :+:    :+:   */
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

void	medium_small(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	t_stack	*current;
	int		larger;

	while (ft_lstsize(*stack_a) > 3)
	{
		current = (*stack_a)->next;
		larger = 0;
		while (current)
		{
			larger += gt(current->content, (*stack_a)->content);
			current = current->next;
		}
		if (larger >= 3)
			pb(stack_b, stack_a, meta);
		else
			ra(stack_a, meta);
	}
	sort_tiny(stack_a, meta);
	if ((*stack_b)->next && is_sorted(*stack_b))
		rb(stack_b, meta);
	while (*stack_b)
		pa(stack_a, stack_b, meta);
}
