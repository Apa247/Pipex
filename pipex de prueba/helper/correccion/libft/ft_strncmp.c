/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:32:12 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 20:51:32 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Compares not more than 'n' characters in the null-terminated strings
**	's1' and 's2'. The comparison is done using unsigned characters, so that
**	`\200' is greater than `\0'.
**	Returns an integer greater than, equal to, or less than 0, according as
**	the string 's1' is greater than, equal to, or less than the string 's2'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --n > 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
