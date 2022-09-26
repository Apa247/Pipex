/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:22:58 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 15:19:30 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst)
	{
		while (*lst)
		{
			aux = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(aux, del);
		}
	}
	*lst = NULL;
}
