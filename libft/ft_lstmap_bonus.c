/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:50:57 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/17 19:37:10 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*one;
	t_list	*new_lst;
	t_list	*tmp;

	one = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			while (one)
			{
				tmp = one->next;
				(*del)(one->content);
				free(one);
				one = tmp;
			}
			return (NULL);
		}
		ft_lstadd_back(&one, new_lst);
		lst = lst->next;
	}
	return (one);
}
