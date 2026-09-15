/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/09/15 20:35:43 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Copy and bubble sort all values from A into an array
static int	*sort_array(t_stack *stack_a, int size)
{
	int	*arr;
	int	i;
	int	tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack_a)
	{
		arr[i++] = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
	i = 0;
	while (++i < size)
	{
		if (arr[i - 1] > arr[i])
		{
			tmp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = tmp;
			i = 0;
		}
	}
	return (arr);
}

// Compute √A sliding window and push values from a rotating A to a rotating B
static void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_meta *meta,
		int size)
{
	int	pushed;
	int	window;

	pushed = 0;
	window = 0;
	while ((window + 1) * (window + 1) <= size)
		window++;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content <= pushed + window)
		{
			pushed++;
			pb(stack_b, stack_a, meta);
			if (ft_lstsize((t_list *)*stack_b) > 1
				&& *(int *)(*stack_b)->content < pushed - window / 2)
				rb(stack_b, meta);
		}
		else
			ra(stack_a, meta);
	}
}

// Rotate B to clip values from either end back to A most efficiently
static void	push_to_a(t_stack **stack_a, t_stack **stack_b, t_meta *meta,
		int size)
{
	int		target;
	int		position;
	int		b_size;
	t_stack	*current;

	target = size;
	while (--target >= 0)
	{
		position = 0;
		current = *stack_b;
		while (current && *(int *)current->content != target && ++position)
			current = current->next;
		if (current)
		{
			b_size = ft_lstsize((t_list *)*stack_b);
			if (position <= b_size / 2)
				while (position-- > 0)
					rb(stack_b, meta);
			else
				while (b_size - position++ > 0)
					rrb(stack_b, meta);
			pa(stack_a, stack_b, meta);
		}
	}
}

// Replace A values with their ranks, then push A to B and back
void	sort_medium(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	int		size;
	int		*sorted;
	int		i;
	t_stack	*current;

	size = ft_lstsize((t_list *)*stack_a);
	sorted = sort_array(*stack_a, size);
	if (size < 2 || !sorted)
		return ;
	current = *stack_a;
	while (current)
	{
		i = 0;
		while (i < size && sorted[i] != *(int *)current->content)
			i++;
		*(int *)current->content = i;
		current = current->next;
	}
	free(sorted);
	push_to_b(stack_a, stack_b, meta, size);
	push_to_a(stack_a, stack_b, meta, size);
}
