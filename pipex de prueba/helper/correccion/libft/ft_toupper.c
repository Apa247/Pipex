/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:33:39 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 19:32:15 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Converts a lower-case letter to the corresponding upper-case letter.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	return (c - 32 * ft_islower(c));
}
