/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42warsaw.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 23:02:40 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/10 23:02:40 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	char	**temp;

	if (!args)
		return ;
	temp = args;
	while (*temp)
		free(*temp++);
	free(args);
}

void	split_args(char ***argv)
{
	char	*new;
	char	*arg;

	new = ft_strdup("");
	while (new && **argv)
	{
		arg = **argv;
		while (*arg == ' ')
			arg++;
		if (!*arg)
			break ;
		arg = ft_strjoin(new, arg);
		free(new);
		new = NULL;
		if (!arg)
			break ;
		new = ft_strjoin(arg, " ");
		free(arg);
		(*argv)++;
	}
	if (**argv)
		*argv = NULL;
	else
		*argv = ft_split(new, ' ');
	free(new);
}
