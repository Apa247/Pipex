/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:50:48 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/26 11:28:16 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns a new string, which is the
**	result of the concatenation of ’s1’ and ’s2’ with a new line character
**	in between.
*/

#include "libft.h"
#include <stdio.h>

char	*ft_strnewline(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(len1 + len2 + 2);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, len1);
	s[len1] = '\n';
	ft_memcpy(s + len1 + 1, s2, len2);
	s[len1 + 1 + len2] = 0;
	return (s);
}
