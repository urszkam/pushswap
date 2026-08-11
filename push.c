/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*first2;

	if (!stack1 || !stack2 || !*stack2)
		return ;
	first2 = *stack2;
	*stack2 = first2->next;
	first2->next = *stack1;
	*stack1 = first2;
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_meta *meta)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	meta->total++;
	meta->pa++;
}

void	pb(t_stack **stack_b, t_stack **stack_a, t_meta *meta)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	meta->total++;
	meta->pb++;
}
