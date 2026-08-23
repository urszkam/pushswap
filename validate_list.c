/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:11:05 by pausulzy          #+#    #+#             */
/*   Updated: 2026/08/23 17:14:54 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Filter flags from argv
static void	filter_flags(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		if ((ft_strlen(argv[i]) != 7 || ft_strncmp(argv[i], "--bench", 7) != 0)
			&& (ft_strlen(argv[i]) != 8 || ft_strncmp(argv[i], "--simple",
					8) != 0) && (ft_strlen(argv[i]) != 8 || ft_strncmp(argv[i],
					"--medium", 8) != 0) && (ft_strlen(argv[i]) != 9
				|| ft_strncmp(argv[i], "--complex", 9) != 0)
			&& (ft_strlen(argv[i]) != 10 || ft_strncmp(argv[i], "--adaptive",
					10) != 0))
			argv[j++] = argv[i];
		i++;
	}
	argv[j] = NULL;
}

// Confirm all entries are digits or +/-
static int	is_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
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
static int	is_integer(char **argv)
{
	int		is_positive;
	char	*num;

	while (*argv)
	{
		num = *argv;
		is_positive = (*num != '-');
		if (*num == '+' || *num == '-')
			num++;
		while (*num == '0')
			num++;
		if (ft_strlen(num) > 10)
			return (0);
		if (ft_strlen(num) == 10)
			if ((is_positive && ft_strncmp("2147483647", num, 10) < 0)
				|| (!is_positive && ft_strncmp("2147483648", num, 10) < 0))
				return (0);
		argv++;
	}
	return (1);
}

// Confirm no duplicates present
static int	is_unique(char **argv)
{
	int	i;
	int	j;

	i = 0;
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
	filter_flags(argc, argv);
	if (!is_digit(argv) || !is_integer(argv) || !is_unique(argv))
		return (ft_putendl_fd("Error", 2), 0);
	return (1);
}
