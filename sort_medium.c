/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/09/21 17:20:26 by pausulzy         ###   ########.fr       */
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

// Rotate B to clip values from either end back to A by target size
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

// Replace A values with their ranks
static void	assign_ranks(t_stack *current, int *sorted, int size)
{
	int	i;

	while (current)
	{
		i = 0;
		while (i < size && sorted[i] != *(int *)current->content)
			i++;
		*(int *)current->content = i;
		current = current->next;
	}
}

// Coordinate sorted array creation, rank replacement, and pushes to and from B
void	sort_medium(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	int	size;
	int	*sorted;

	size = ft_lstsize(*stack_a);
	if (size <= 5)
	{
		medium_small(stack_a, stack_b, meta);
		return ;
	}
	sorted = sort_array(*stack_a, size);
	if (!sorted)
	{
		ft_lstclear(stack_a, free);
		ft_lstclear(stack_b, free);
		write(2, "Error\n", 6);
		exit(1);
	}
	assign_ranks(*stack_a, sorted, size);
	free(sorted);
	push_to_b(stack_a, stack_b, meta, size);
	push_to_a(stack_a, stack_b, meta, size);
}
