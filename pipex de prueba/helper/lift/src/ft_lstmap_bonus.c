/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:36:35 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/23 10:53:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux;

	new_lst = NULL;
	if (lst && f)
	{
		aux = ft_lstnew((*f)(lst->content));
		while (lst && aux)
		{
			ft_lstadd_back(&new_lst, aux);
			lst = lst->next;
			if (lst)
				aux = ft_lstnew((*f)(lst->content));
		}
		if (!aux)
		{
			ft_lstclear(&new_lst, del);
			new_lst = NULL;
		}
	}
	return (new_lst);
}
