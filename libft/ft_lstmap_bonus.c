/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:45:38 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/07 17:43:21 by akharkho         ###   ########.fr       */
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

// void *f(void *content)
// {
//     char *str;
// 	int i;
	
// 	str = ft_strdup((char *)content );
//     if (!str)
//         return (NULL);
//     i = 0;
//     while (str[i])
//     {
//         str[i] = ft_toupper(str[i]);
//         i++;
//     }
//     return (str);
// }
// void delete(void *content)
// {
// 	free(content);
// }
// int main (){
// 	t_list *lst;
// 	t_list *lst1;
// 	t_list *lst2;
	
// 	lst = ft_lstnew(ft_strdup("adnan"));
// 	lst1 = ft_lstnew(ft_strdup("ali"));
// 	lst2 = ft_lstnew(ft_strdup("ahmed"));
// 	ft_lstadd_front(&lst, lst1);
// 	ft_lstadd_front(&lst, lst2);
// 	 t_list *temp = lst;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)(*temp).content);
// 		temp = temp->next;
// 	}
// 	printf("|||||||||||||||\n");
// 	t_list *new_list;
// 	new_list = ft_lstmap(lst, &f, &delete);
// 	while (new_list)
// 	{
// 		printf("%s\n", (char *)new_list->content);
// 		new_list = new_list->next;
// 	}
// 	//    ft_lstclear(&lst, &delete);
//     // ft_lstclear(&new_list, &delete);
// }
