/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42warsaw.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (gt(stack->content, stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	needs_swap_in_front(t_stack *stack, void *max)
{
	while (stack->next)
	{
		if (eq(stack->content, max))
			return (0);
		if (gt(stack->content, stack->next->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	simple_small(t_stack **stack, t_meta *meta)
{
	void	*max;
	t_stack	*temp;

	max = (*stack)->content;
	temp = (*stack)->next;
	while (temp)
	{
		if (gt(temp->content, max))
			max = temp->content;
		temp = temp->next;
	}
	while (!is_sorted(*stack))
	{
		if (gt((*stack)->content, (*stack)->next->content))
			sa(stack, meta);
		if (!eq(max, ft_lstlast(*stack)->content)
			&& lt((*stack)->content, ft_lstlast(*stack)->content))
			rra(stack, meta);
		else if (needs_swap_in_front(*stack, max))
			ra(stack, meta);
		else if (!eq(max, ft_lstlast(*stack)->content))
			rra(stack, meta);
	}
}

static void	push_min(t_stack **st, t_stack **stack_b, t_meta *meta)
{
	t_stack	*smallest;
	t_stack	*current;

	smallest = *st;
	current = (*st)->next;
	while (current)
	{
		if (lt(current->content, smallest->content))
			smallest = current;
		current = current->next;
	}
	while (!eq((*st)->content, smallest->content))
	{
		if (ft_lstsize(*st) - ft_lstsize(smallest) <= ft_lstsize(*st) / 2)
			ra(st, meta);
		else
			rra(st, meta);
	}
	pb(stack_b, st, meta);
}

void	complex_small(t_stack **st, t_stack **stack_b, t_meta *meta,
	t_complex_meta *complex)
{
	if (complex->iterations == 3)
		push_min(st, stack_b, meta);
	if (gt((*st)->content, ft_lstlast(*st)->content) && complex->iterations < 2)
		sa(st, meta);
	if (complex->iterations > 1 && lt((*st)->content, (*st)->next->content))
		sa(st, meta);
	if (complex->iterations >= 2)
	{
		ra(st, meta);
		ra(st, meta);
		if (complex->len > 3 && gt((*st)->content, (*st)->next->content))
			sa(st, meta);
		rra(st, meta);
		if (gt((*st)->content, ft_lstlast(*st)->content))
			sa(st, meta);
		rra(st, meta);
		if (gt((*st)->content, ft_lstlast(*st)->content))
			sa(st, meta);
		simple_small(st, meta);
		if (complex->iterations == 3)
			pa(st, stack_b, meta);
	}
}
