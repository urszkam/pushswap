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

int	is_max_closer_to_start(t_stack *stack_b, void *max)
{
	int	size;
	int	idx_from_start;
	int	idx_from_end;

	idx_from_start = 0;
	size = ft_lstsize(stack_b);
	while (stack_b && !eq(max, stack_b->content))
	{
		idx_from_start++;
		stack_b = stack_b->next;
	}
	idx_from_end = size - idx_from_start;
	return (idx_from_start < idx_from_end);
}

void	order_stack(t_stack **stack_b, t_meta *meta, void *max)
{
	void	(*func)(t_stack **, t_meta *);

	if (eq(max, (*stack_b)->content))
		return ;
	if (is_max_closer_to_start(*stack_b, max))
		func = rb;
	else
		func = rrb;
	while (!eq(max, (*stack_b)->content))
		func(stack_b, meta);
}

static int	find_target(t_stack *stack_b, int number)
{
	t_stack	*previous;
	int		index;
	int		previous_value;
	int		current_value;

	previous = ft_lstlast(stack_b);
	index = 0;
	while (stack_b)
	{
		previous_value = *(int *)previous->content;
		current_value = *(int *)stack_b->content;
		if ((previous_value > current_value
				&& number < previous_value && number > current_value)
			|| (previous_value < current_value
				&& (number > current_value || number < previous_value)))
			return (index);
		previous = stack_b;
		stack_b = stack_b->next;
		index++;
	}
	return (0);
}

static void	rotate_to_target(t_stack **stack_b, int index, t_meta *meta)
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
		target = find_target(*stack_b, *(int *)(*stack_a)->content);
		rotate_to_target(stack_b, target, meta);
		if (lt(max, (*stack_a)->content))
			max = (*stack_a)->content;
		pb(stack_b, stack_a, meta);
	}
	order_stack(stack_b, meta, max);
	while (*stack_b)
		pa(stack_a, stack_b, meta);
}
