/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/29 11:17:45 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}t_stack;

t_stack	*ft_newnode(int value, int index);
void	ft_nodeadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_newnode(int value, int index);
long		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);

#endif