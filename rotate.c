/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **stack_a, t_meta *meta)
{
	rotate(stack_a);
	ft_printf("ra\n");
	meta->total++;
	meta->ra++;
}

void	rb(t_stack **stack_b, t_meta *meta)
{
	rotate(stack_b);
	ft_printf("rb\n");
	meta->total++;
	meta->rb++;
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	meta->total++;
	meta->rr++;
}
