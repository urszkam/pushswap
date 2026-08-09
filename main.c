/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:49:22 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 11:52:19 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	double	disorder;
	int		algorithm;
	int		bench;
	stack_t	*stack_a;
	meta_t	*sort_metdata;

	if (argc > 1)
	{
		if (!validate_list(++argv))
		{
			print_err();
			return (1);
		}
		stack_a = populate_stack(argv);
		disorder = calc_disorder(stack_a);
		algorithm = extract_flags(argv, disorder, *bench);
		sort_stack(*stack_a, *sort_metadata, disorder, algorithm);
		print_operations(sort_metadata->ops);
		if (is_bench_flag(argv))
			print_bench(sort_metadata);
	}
	return (0);
}
