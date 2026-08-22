/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:11:05 by pausulzy          #+#    #+#             */
/*   Updated: 2026/08/22 10:17:56 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Filter flags
int	is_flag(char *arg)
{
	if (arg[0] != '-' || arg[1] != '-')
		return (0);
	if ((ft_strncmp(arg, "--simple", 8) == 0 && arg[8] == '\0')
		|| (ft_strncmp(arg, "--medium", 8) == 0 && arg[8] == '\0')
		|| (ft_strncmp(arg, "--complex", 9) == 0 && arg[9] == '\0')
		|| (ft_strncmp(arg, "--adaptive", 10) == 0 && arg[10] == '\0'))
		return (1);
	return (0);
}

// Return argv with flags filtered out
static char	**filter_flags(int argc, char **argv)
{
	char	**filtered;
	int		i;
	int		count;

	filtered = ft_calloc(argc + 1, sizeof(char *));
	if (!filtered)
		return (NULL);
	i = 1;
	count = 0;
	while (argv[i])
	{
		if (!is_flag(argv[i]))
			filtered[count++] = argv[i];
		i++;
	}
	filtered[count] = NULL;
	return (filtered);
}

// Confirm all entries are leading +/- or non-duplicate digits
static int	check_numbers(char **argv)
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
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		j = i + 1;
		while (argv[j])
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				return (0);
		i++;
	}
	return (1);
}

// Confirm all entries are within int range
static int	check_range(char **argv)
{
	int			i;
	int			j;
	int			sign;
	long long	value;

	i = 0;
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
		if (sign == -1)
			value = -value;
		if (value < -2147483648LL || value > 2147483647LL)
			return (0);
		i++;
	}
	return (1);
}

// Validate list
int	validate_list(int argc, char **argv)
{
	char	**nums;

	if (argc < 2)
		return (0);
	nums = filter_flags(argc, argv);
	if (!nums || !check_numbers(nums) || !check_range(nums))
		return (ft_putendl_fd("Error", 2), 0);
	free(nums);
	return (1);
}
