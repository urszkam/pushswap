/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	penultimate = *stack;
	last = ft_lstlast(*stack);
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, t_meta *meta)
{
	rotate_reverse(stack_a);
	ft_printf("rra\n");
	meta->total++;
	meta->rra++;
}

void	rrb(t_stack **stack_b, t_meta *meta)
{
	rotate_reverse(stack_b);
	ft_printf("rrb\n");
	meta->total++;
	meta->rrb++;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	ft_printf("rrr\n");
	meta->total++;
	meta->rrr++;
}
