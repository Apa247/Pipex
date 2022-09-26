/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:26:08 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 21:20:14 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Converts an upper-case letter to the corresponding lower-case letter.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	return (c + 32 * ft_isupper(c));
}
