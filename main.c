/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%d\n", *(int *)stack->content);
// 		stack = stack->next;
// 	}
// }

void	sort_stack(
	t_stack **stack_a, double disorder, char *algorithm, t_meta *meta
)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (equals(algorithm, "simple")
		|| (equals(algorithm, "adaptive") && disorder <= 0.2))
		sort_simple(stack_a, &stack_b, meta);
	else if (equals(algorithm, "medium")
		|| (equals(algorithm, "adaptive") && disorder < 0.5))
		sort_medium(stack_a, &stack_b, meta);
	else
		sort_complex(stack_a, &stack_b, meta);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	// double	disorder;
	char	*algorithm_flag;
	int		bench;
	t_meta	meta;
	// t_stack	*stack_a;

	if (argc > 1)
	{
		ft_bzero(&meta, sizeof(t_meta));
		argv++;
		// if (!validate_list(argv)) //TODO
		// {
		// 	ft_putendl_fd("Error", 2);
		// 	return (1);
		// }
		extract_flags(&argv, &algorithm_flag, &bench);
		// stack_a = populate_stack(argv); //TODO
		// print_stack(stack_a);
		// disorder = compute_disorder(stack_a);
		// sort_stack(&stack_a, disorder, algorithm_flag, &meta);
		// if (bench)
		// 	print_bench(disorder, algorithm_flag, meta);
		// free_stack(&stack_a);
	}
	return (0);
}
