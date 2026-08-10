/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:49:22 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 21:42:34 by urkamins         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

// static void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%d\n", stack->num);
// 		stack = stack->next;
// 	}
// }

void	sort_stack(t_stack **stack_a, double disorder, char *algorithm)
{
	if (equals(algorithm, "simple")
		|| (equals(algorithm, "adaptive") && disorder <= 0.2))
		sort_simple(stack_a);
	else if (equals(algorithm, "medium")
		|| (equals(algorithm, "adaptive") && disorder < 0.5))
		sort_medium(stack_a);
	else
		sort_complex(stack_a);
}

int	main(int argc, char **argv)
{
	// double	disorder;
	char	*algorithm_flag;
	int		bench;
	// int		*ops;
	// t_stack	*stack_a;

	if (argc > 1)
	{
		argv++;
		// if (!validate_list(argv))
		// {
		// 	ft_putendl_fd("Error", 2);
		// 	return (1);
		// }
		extract_flags(&argv, &algorithm_flag, &bench);
		// stack_a = populate_stack(argv);
		// print_stack(stack_a);
		// disorder = compute_disorder(stack_a);
		// sort_stack(&stack_a, disorder, algorithm_flag);
		// if (bench)
		// 	print_bench(disorder, algorithm_flag);
		// free_stack(&stack_a);
	}
	return (0);
}
