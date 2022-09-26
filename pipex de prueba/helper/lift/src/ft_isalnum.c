/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:16:44 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/13 14:02:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	alnum;

	alnum = 0;
	if (ft_isalpha(c) || ft_isdigit(c))
		alnum = 1;
	return (alnum);
}
