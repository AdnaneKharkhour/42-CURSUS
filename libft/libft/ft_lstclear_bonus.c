/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:28:05 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/31 19:46:28 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*follow;

	if (!*lst || !lst)
		return ;
	curr = *lst;
	while (curr->next)
	{
		follow = curr->next;
		del(curr->content);
		free(curr);
		curr = follow;
	}
	*lst = NULL;
}
