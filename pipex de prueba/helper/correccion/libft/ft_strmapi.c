/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 03:58:23 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 20:52:44 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Applies the function 'f' to each character of the string 's' to create a
**	new string (with malloc(3)) resulting from successive applications of 'f'.
**	Returns the string created from the successive applications of 'f'.
**	Returns NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mem;
	size_t	i;

	mem = malloc(ft_strlen(s) + 1);
	if (!s || !f || !mem)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mem[i] = f(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
