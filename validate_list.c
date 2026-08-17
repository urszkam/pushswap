/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:11:05 by pausulzy          #+#    #+#             */
/*   Updated: 2026/08/17 15:11:06 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Confirm all entries are digits or +/-
static int	check_digits(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		return (1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
// Confirm all entries are within int range
static int	check_range(char **argv)
{
	int		i;
	int		j;
	int		sign;
	long	value;

	i = 1;
	while (argv[i])
	{
		j = 0;
		sign = 1;
		value = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			if (argv[i][j++] == '-')
				sign = -1;
		while (argv[i][j])
			value = value * 10 + (argv[i][j++] - '0');
		value *= sign;
		if (value < -2147483648 || value > 2147483647)
			return (0);
		i++;
	}
	return (1);
}
// Confirm no duplicates present
static int	check_repeats(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				return (0);
		i++;
	}
	return (1);
}

// Validate list
int	validate_list(int argc, char **argv)
{
	if (argc < 2 || !argv || !*argv)
		return (ft_putendl_fd("Error", 2), 0);
	if (!check_digits(argv))
		return (ft_putendl_fd("Error", 2), 0);
	if (!check_range(argv))
		return (ft_putendl_fd("Error", 2), 0);
	if (!check_repeats(argv))
		return (ft_putendl_fd("Error", 2), 0);
	return (1);
}
