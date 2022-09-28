/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:36:43 by daparici          #+#    #+#             */
/*   Updated: 2022/04/05 20:57:50 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	if (!lst)
		return ;
	if (*lst)
	{
		dest = ft_lstlast(*(lst));
		dest->next = new;
	}
	else
		(*lst) = new;
}
