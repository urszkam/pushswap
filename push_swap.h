/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:26:49 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 12:27:15 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int					num;
	struct s_content	*prev;
	struct s_content	*next;
}	t_stack;

int	extract_flags(char **argv, int disorder, int *bench);

#endif
