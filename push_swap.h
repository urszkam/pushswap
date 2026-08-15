/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:26:49 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 21:37:19 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef t_list	t_stack;

typedef struct s_meta
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_meta;

typedef struct s_complex_meta
{
	int	iterations;
	int	run_size;
	int	len;
	int	to_b;
	int	remaining_a;
	int	remaining_b;
	int	current_a;
	int	current_b;
}	t_complex_meta;

void	extract_flags(char ***argv, char **algorithm, int *bench);
void	print_bench(double disorder, char *algorithm, t_meta meta);
void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_meta *meta);
void	sort_medium(t_stack **stack_a, t_stack **stack_b, t_meta *meta);
void	sort_complex(t_stack **stack_a, t_stack **stack_b, t_meta *meta);

void	pa(t_stack **stack_a, t_stack **stack_b, t_meta *meta);
void	pb(t_stack **stack_b, t_stack **stack_a, t_meta *meta);
void	sa(t_stack **stack_a, t_meta *meta);
void	sb(t_stack **stack_b, t_meta *meta);
void	ss(t_stack **stack_a, t_stack **stack_b, t_meta *meta);
void	ra(t_stack **stack_a, t_meta *meta);
void	rb(t_stack **stack_b, t_meta *meta);
void	rr(t_stack **stack_a, t_stack **stack_b, t_meta *meta);
void	rra(t_stack **stack_a, t_meta *meta);
void	rrb(t_stack **stack_b, t_meta *meta);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_meta *meta);

int		is_flag(char *s);
int		equals(char *s1, char *s2);
int		lt(void *num1, void *num2);
int		gt(void *num1, void *num2);
int		eq(void *num1, void *num2);
int		min(int num1, int num2);
int		max(int num1, int num2);
int		compute_iterations(int size);

void	complex_push(t_stack **from, t_stack **to,
			t_meta *meta, int to_b);
void	complex_swap(t_stack **stack, t_meta *meta, int to_b);
void	complex_rotate(t_stack **stack, t_meta *meta, int to_b);
void	complex_reverse_rotate(t_stack **stack, t_meta *meta, int to_b);

double	compute_disorder(t_stack *stack_a);

#endif
