/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compute_complex_metadata(t_complex_meta *meta, t_stack *stack)
{
	meta->len = ft_lstsize(stack);
	meta->iterations = compute_iterations(meta->len);
	meta->to_b = 1;
	meta->run_size = 2;
	meta->remaining_b = meta->len /2;
	meta->remaining_a = meta->len - meta->remaining_b;
}

void	merge_run(t_stack **stack_a, t_stack **stack_b,
	t_meta *meta, t_complex_meta *complex)
{
	int	take_a;

	while (complex->current_a > 0 || complex->current_b > 0)
	{
		take_a = (complex->current_a > 0);
		if (take_a && complex->current_b > 0)
			take_a = lt((*stack_a)->content, (*stack_b)->content);
		if (take_a && complex->to_b)
			pb(stack_b, stack_a, meta);
		else if (!take_a && !complex->to_b)
			pa(stack_a, stack_b, meta);
		if (complex->to_b)
			rb(stack_b, meta);
		else
			ra(stack_a, meta);
		if (take_a)
			complex->current_a--;
		else
			complex->current_b--;
	}
}

static void	merge_sort_iteration(t_stack **stack_a, t_stack **stack_b,
	t_meta *meta, t_complex_meta *complex)
{
	while (complex->remaining_a > 0 || complex->remaining_b > 0)
	{
		complex->current_a = min(max(complex->remaining_a, 0),
			complex->run_size / 2);
		complex->current_b = min(max(complex->remaining_b, 0),
			complex->run_size / 2);
		if (!complex->iterations)
			complex->to_b = 0;
		else
			complex->to_b = !complex->to_b;
		merge_run(stack_a, stack_b, meta, complex);
		complex->remaining_a -= (complex->run_size / 2);
		complex->remaining_b -= (complex->run_size / 2);
	}
}

void	sort_complex(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	t_complex_meta	complex;
	int				initial_push_size;

	ft_bzero(&complex, sizeof(t_complex_meta));
	compute_complex_metadata(&complex, *stack_a);
	initial_push_size = complex.remaining_b;
	while (initial_push_size--)
		pb(stack_b, stack_a, meta);
	while (complex.iterations--)
	{
		merge_sort_iteration(stack_a, stack_b, meta, &complex);
		complex.run_size *= 2;
		complex.remaining_b = ft_lstsize(*stack_b);
		complex.remaining_a = ft_lstsize(*stack_a);
	}
}
