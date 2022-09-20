/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:10:21 by daparici          #+#    #+#             */
/*   Updated: 2022/04/04 13:40:47 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*dest;

	if (!lst || !del)
		return ;
	if (*lst)
	{
		while (*lst)
		{
			dest = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = dest;
		}
		*lst = NULL;
	}
	else
		*lst = NULL;
}
