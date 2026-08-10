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

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ops
{
	char			*op;
	int				counter;
	struct s_stack	*next;
}	t_ops;

void	extract_flags(char ***argv, char **algorithm, int *bench);
void	print_bench(double disorder, char *algorithm);
void	sort_simple(t_stack **stack_a);
void	sort_medium(t_stack **stack_a);
void	sort_complex(t_stack **stack_a);

int		is_flag(char *s);
int		equals(char *s1, char *s2);

double	compute_disorder(t_stack *stack_a);

// t_stack	*populate_stack(char **argv);
// void	free_stack(t_stack **stack);

#endif
