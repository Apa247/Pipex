/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:34:42 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 20:20:25 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Locates the last occurrence of 'c' (converted to a char) in the
**	string pointed to by 's'.  The terminating null character is
**	considered to be part of the string; therefore if ,'c' is `\0',
**	the functions locate the terminating `\0'.
**	Returns a pointer to the located character, or NULL if the
**	character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*t;

	t = NULL;
	while (*s)
		if (*s++ == c)
			t = s - 1;
	if (!c)
		return ((char *)s);
	return ((char *)t);
}
