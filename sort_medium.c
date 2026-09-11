/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/09/04 17:36:33 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate rank (position by ascending value)
static int	get_rank(t_stack *stack, int value)
{
	int	rank;

	rank = 0;
	while (stack)
	{
		if (*(int *)stack->content < value)
			rank++;
		stack = stack->next;
	}
	return (rank);
}

// Find next required value in B, optimize rotation and pop back to A
static void	push_to_a(t_stack **stack_a, t_stack **stack_b, t_meta *meta,
		int target)
{
	t_stack	*cur;
	int		pos;
	int		size;

	cur = *stack_b;
	pos = 0;
	while (cur && get_rank(*stack_b, *(int *)cur->content) != target)
	{
		cur = cur->next;
		pos++;
	}
	size = ft_lstsize(*stack_b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(stack_b, meta);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rrb(stack_b, meta);
	}
	pa(stack_a, stack_b, meta);
}

// Move values from A to B via expanding window
static void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_meta *m, int size)
{
	int	window;
	int	i;
	int	rank;

	window = 15;
	if (size > 100)
		window = 30;
	i = 0;
	while (*stack_a)
	{
		rank = get_rank(*stack_a, *(int *)(*stack_a)->content) + i;
		if (rank <= i)
		{
			pb(stack_b, stack_a, m);
			rb(stack_b, m);
			i++;
		}
		else if (rank <= i + window)
		{
			pb(stack_b, stack_a, m);
			i++;
		}
		else
			ra(stack_a, m);
	}
}

// Send values from A to B in chunks then return to A in descending
void	sort_medium(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	int	size;
	int	target;

	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	push_to_b(stack_a, stack_b, meta, size);
	target = size - 1;
	while (target >= 0)
	{
		push_to_a(stack_a, stack_b, meta, target);
		target--;
	}
}
