/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/13 14:42:23 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
}

t_stack	*populate_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*node;
	int		*value;
	int		i;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		value = malloc(sizeof(int));
		if (!value)
			return (free_stack(&stack), NULL);
		*value = ft_atoi(argv[i]);
		node = ft_lstnew(value);
		if (!node)
			return (free(value), free_stack(&stack), NULL);
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

void	sort_stack(t_stack **stack_a, double disorder, char *algorithm,
		t_meta *meta)
{
	t_stack	*stack_b;

	if (!stack_a || !*stack_a || !(*stack_a)->next || disorder == 0)
		return ;
	stack_b = NULL;
	if (equals(algorithm, "simple") || (equals(algorithm, "adaptive")
			&& disorder <= 0.2))
		sort_simple(stack_a, &stack_b, meta);
	else if (equals(algorithm, "medium") || (equals(algorithm, "adaptive")
			&& disorder < 0.5))
		sort_medium(stack_a, &stack_b, meta);
	else
		sort_complex(stack_a, &stack_b, meta);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	double	disorder;
	char	*algorithm_flag;
	int		bench;
	t_meta	meta;
	t_stack	*stack_a;

	if (argc == 1)
		return (1);
	ft_bzero(&meta, sizeof(t_meta));
	argv++; // REMOVE WHEN THE LINE BELOW IS UNCOMMENTED
	// if (!validate_list(++argv)) //TODO
	// {
	// 	ft_putendl_fd("Error", 2);
	// 	return (1);
	// }
	extract_flags(&argv, &algorithm_flag, &bench);
	stack_a = populate_stack(argv);
	if (!stack_a)
		return (1);
	print_stack(stack_a);
	disorder = compute_disorder(stack_a);
	sort_stack(&stack_a, disorder, algorithm_flag, &meta);
	if (bench)
		print_bench(disorder, algorithm_flag, meta);
	free_stack(&stack_a);
	return (0);
}
