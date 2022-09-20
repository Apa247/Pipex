/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:39:20 by daparici          #+#    #+#             */
/*   Updated: 2022/04/06 18:09:46 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*check;
	void	*content;

	if (!f)
		return (NULL);
	dest = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (content)
		{
			check = ft_lstnew(content);
			if (!check)
			{
				if (del)
					del(content);
				ft_lstclear(&dest, del);
				return (NULL);
			}
			ft_lstadd_back(&dest, check);
			lst = lst->next;
		}
	}
	return (dest);
}
