/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42warsaw.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s)
{
	return (!strncmp(s, "--", 2));
}

int	equals(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] == (unsigned char)s2[i]);
}

void	extract_flags(char ***argv, char **algorithm, int *bench)
{
	int		idx;
	char	*algorithms[3];

	algorithms[0] = "simple";
	algorithms[1] = "medium";
	algorithms[2] = "complex";
	*algorithm = "adaptive";
	*bench = 0;
	while (argv && *argv && **argv && is_flag(**argv))
	{
		idx = 0;
		while (idx < 3)
			if (equals(**argv + 2, algorithms[idx++]))
				*algorithm = algorithms[idx - 1];
		if (equals(**argv + 2, "bench"))
			*bench = 1;
		free(**argv);
		idx = 0;
		while ((*argv)[idx + 1])
		{
			(*argv)[idx] = (*argv)[idx + 1];
			idx++;
		}
		(*argv)[idx] = NULL;
	}
}

double	compute_disorder(t_stack *stack_a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*inner;

	mistakes = 0;
	total_pairs = 0;
	if (!stack_a->next)
		return (0);
	while (stack_a->next)
	{
		inner = stack_a->next;
		while (inner)
		{
			total_pairs += 1;
			if (*(int *)stack_a->content > *(int *)inner->content)
				mistakes += 1;
			inner = inner->next;
		}
		stack_a = stack_a->next;
	}
	return ((double) mistakes / total_pairs);
}
