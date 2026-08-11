/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder)
{
	int	whole_disorder;

	whole_disorder = disorder * 10000;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole_disorder / 100, 2);
	ft_putchar_fd('.', 2);
	if (whole_disorder % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(whole_disorder % 100, 2);
	ft_putendl_fd("%", 2);
}

void	print_algorithm(char *algorithm, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putchar_fd(ft_toupper(*algorithm), 2);
	ft_putstr_fd(algorithm + 1, 2);
	ft_putstr_fd(" / ", 2);
	if (equals(algorithm, "simple")
		|| (equals(algorithm, "adaptive") && disorder <= 0.2))
		ft_putendl_fd("O(n^2)", 2);
	else if (equals(algorithm, "medium")
		|| (equals(algorithm, "adaptive") && disorder < 0.5))
		ft_putendl_fd("O(n√n)", 2);
	else
		ft_putendl_fd("O(n log n)", 2);
}

void	print_total(t_meta meta)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(meta.total, 2);
	ft_putendl_fd("", 2);
}

void	print_operations(t_meta meta)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(meta.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(meta.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(meta.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(meta.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(meta.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(meta.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(meta.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(meta.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(meta.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(meta.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(meta.rrr, 2);
	ft_putendl_fd("", 2);
}

void	print_bench(double disorder, char *algorithm, t_meta meta)
{
	print_disorder(disorder);
	print_algorithm(algorithm, disorder);
	print_total(meta);
	print_operations(meta);
}
