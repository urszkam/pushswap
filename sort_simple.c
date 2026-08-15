/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index(t_stack *stack, void *target)
{
	int	index;

	index = 0;
	while (stack && !eq(target, stack->content))
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

static int	find_target(t_stack *stack_b, void *number, void *max)
{
	t_stack	*previous;
	int		index;

	previous = ft_lstlast(stack_b);
	index = 0;
	while (stack_b)
	{
		if ((lt(number, previous->content)
				&& gt(number, stack_b->content))
			|| (eq(max, stack_b->content)
				&& (gt(number, stack_b->content)
					|| lt(number, previous->content))))
			return (index);
		previous = stack_b;
		stack_b = stack_b->next;
		index++;
	}
	return (0);
}

static void	rotate_to_value(t_stack **stack_b, int index, t_meta *meta)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (index <= size / 2)
		while (index--)
			rb(stack_b, meta);
	else
	{
		index = size - index;
		while (index--)
			rrb(stack_b, meta);
	}
}

void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	void	*max;
	int		target;

	max = (*stack_a)->content;
	pb(stack_b, stack_a, meta);
	while (*stack_a)
	{
		target = find_target(*stack_b, (*stack_a)->content, max);
		rotate_to_value(stack_b, target, meta);
		if (lt(max, (*stack_a)->content))
			max = (*stack_a)->content;
		pb(stack_b, stack_a, meta);
	}
	target = find_index(*stack_b, max);
	rotate_to_value(stack_b, target, meta);
	while (*stack_b)
		pa(stack_a, stack_b, meta);
}
