/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urkamins <urkamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:49:52 by urkamins          #+#    #+#             */
/*   Updated: 2026/08/09 20:49:52 by urkamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
