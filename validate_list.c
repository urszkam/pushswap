/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:11:05 by pausulzy          #+#    #+#             */
/*   Updated: 2026/08/22 08:06:02 by pausulzy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Filter flags
int	is_flag(char *arg)
{
	if (arg[0] != '-' || arg[1] != '-')
		return (0);
	if ((ft_strncmp(arg, "--simple", 9) == 0 && arg[8] == '\0')
		|| (ft_strncmp(arg, "--medium", 9) == 0 && arg[8] == '\0')
		|| (ft_strncmp(arg, "--complex", 10) == 0 && arg[9] == '\0')
		|| (ft_strncmp(arg, "--adaptive", 11) == 0 && arg[10] == '\0'))
		return (1);
	return (0);
}

// Return argv with flags filtered out
static char	**filter_flags(char **argv)
{
	char	**filtered;
	int		i;
	int		count;

	count = 0;
	i = 1;
	while (argv[i])
		if (!is_flag(argv[i++]))
			count++;
	if (count == 0)
		return (NULL);
	filtered = ft_calloc(count + 1, sizeof(char *));
	if (!filtered)
		return (NULL);
	i = 1;
	count = 0;
	while (argv[i])
		if (!is_flag(argv[i]))
			filtered[count++] = argv[i++];
	return (filtered);
}

// Confirm all entries are digits or +/-
static int	check_digits(char **argv)
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
		{
			if ((sign == -1 && value > (2147483648L - (argv[i][j] - '0')) / 10)
				|| (value > (2147483647L - (argv[i][j] - '0')) / 10))
				return (0);
			else
				value = value * 10 + (argv[i][j++] - '0');
		}
		i++;
	}
	return (1);
}

// Confirm no duplicates present
static int	check_repeats(char **argv)
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
	char	**nums;

	if (argc < 2)
		return (0);
	nums = filter_flags(argv);
	if (!nums || !check_digits(nums) || !check_range(nums)
		|| !check_repeats(nums))
		return (ft_putendl_fd("Error", 2), 0);
	free(nums);
	return (1);
}
