/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/09/01 13:50:40 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get min and max values from stack
static void	get_range(t_stack *stack_a, int *min, int *max)
{
	int	value;

	*min = *((int *)stack_a->content);
	*max = *min;
	while (stack_a)
	{
		value = *((int *)stack_a->content);
		if (value < *min)
			*min = value;
		if (value > *max)
			*max = value;
		stack_a = stack_a->next;
	}
}

// Put values in their corresponding buckets
static int	get_bucket(int value, int min, int bucket_count, int bucket_size)
{
	int	bucket_target;

	bucket_target = (value - min) / bucket_size;
	if (bucket_target >= bucket_count)
		bucket_target = bucket_count - 1;
	if (bucket_target < 0)
		bucket_target = 0;
	return (bucket_target);
}

// Rotate A to distribute values to B by buckets, largest first
static void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	int	min;
	int	max;
	int	bucket_count;
	int	bucket_size;
	int	bucket_target;

	get_range(*stack_a, &min, &max);
	bucket_count = 0;
	while ((bucket_count + 1) * (bucket_count + 1) <= ft_lstsize(*stack_a))
		bucket_count++;
	if (bucket_count < 2)
		bucket_count = 2;
	bucket_size = (max - min) / bucket_count + 1;
	bucket_target = bucket_count;
	while (--bucket_target >= 0)
	{
		max = ft_lstsize(*stack_a);
		while (max-- > 0)
			if (get_bucket(*((int *)(*stack_a)->content), min, bucket_count,
					bucket_size) == bucket_target)
				pb(stack_b, stack_a, meta);
			else
				ra(stack_a, meta);
	}
}

// Return the position of the largest value in the stack
static int	find_max_pos(t_stack *stack)
{
	t_stack	*cur;
	int		best_val;
	int		best_pos;
	int		pos;

	cur = stack;
	best_val = *((int *)cur->content);
	best_pos = 0;
	pos = 0;
	while (cur)
	{
		if (*((int *)cur->content) > best_val)
		{
			best_val = *((int *)cur->content);
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best_pos);
}

// Main sort function, rotating B to pop and push highest values onto A
void	sort_medium(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	int	len;
	int	best_pos;
	int	i;

	if (ft_lstsize(*stack_a) <= 1)
		return ;
	push_to_b(stack_a, stack_b, meta);
	while ((len = ft_lstsize(*stack_b)) > 0)
	{
		best_pos = find_max_pos(*stack_b);
		if (best_pos <= len / 2)
		{
			i = 0;
			while (i++ < best_pos)
				rb(stack_b, meta);
		}
		else
		{
			i = best_pos;
			while (i++ < len)
				rrb(stack_b, meta);
		}
		pa(stack_a, stack_b, meta);
	}
}
