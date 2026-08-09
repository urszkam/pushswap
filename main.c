/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:49:22 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 12:12:44 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	double	disorder;
	int		algorithm;
	int		bench;
	stack_t	*stack_a;
	ops_t	*ops;

	if (argc > 1)
	{
		if (!validate_list(++argv))
		{
			print_err();
			return (1);
		}
		stack_a = populate_stack(argv);
		disorder = calc_disorder(stack_a);
		algorithm = extract_flags(argv, disorder, &bench);
		ops = sort_stack(&stack_a, disorder, algorithm);
		if (bench)
			print_bench(ops);
	}
	return (0);
}
