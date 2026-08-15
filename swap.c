/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
}

void	sa(t_stack **stack_a, t_meta *meta)
{
	swap(stack_a);
	ft_printf("sa\n");
	meta->total++;
	meta->sa++;
}

void	sb(t_stack **stack_b, t_meta *meta)
{
	swap(stack_b);
	ft_printf("sb\n");
	meta->total++;
	meta->sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	meta->total++;
	meta->ss++;
}

void    complex_swap(t_stack **stack, t_meta *meta, int to_b)
{
    if (to_b)
        sb(stack, meta);
    else
        sa(stack, meta);
}