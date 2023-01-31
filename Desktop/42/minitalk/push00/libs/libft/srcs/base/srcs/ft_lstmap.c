/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:02:24 by nomoulin          #+#    #+#             */
/*   Updated: 2022/11/20 15:31:58 by nomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*tmp;

	if (lst && f && del)
	{
		mapped_lst = ft_lstnew(f(lst->content));
		lst = lst->next;
		while (lst)
		{
			tmp = ft_lstnew(f(lst->content));
			if (!tmp)
			{
				ft_lstclear(&lst, del);
				return (NULL);
			}
			ft_lstadd_back(&mapped_lst, tmp);
			lst = lst->next;
		}
		return (mapped_lst);
	}
	return (NULL);
}
