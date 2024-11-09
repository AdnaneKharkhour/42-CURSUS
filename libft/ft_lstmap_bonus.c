/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:45:38 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/09 17:33:04 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista;
	t_list	*node;
	void	*par;

	while (!lst || !f || !del)
		return (NULL);
	lista = NULL;
	while (lst)
	{
		par = f(lst->content);
		node = ft_lstnew(par);
		if (!node)
		{
			ft_lstclear(&lista, del);
			free(par);
			return (NULL);
		}
		ft_lstadd_back(&lista, node);
		lst = lst->next;
	}
	return (lista);
}


// int main (){
// 	t_list	*(*myfunc)(t_list *, void *(*)(void *), void (*)(void *)) = ft_lstmap;
// 	t_list	*(*myfunc[])(t_list *, void *(*)(void *), void (*)(void *)) = {ft_lstmap};
// 	myfunc[](list,ft_toupper,free);
// }