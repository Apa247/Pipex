/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:22:41 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/21 19:16:58 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns an array of strings obtained
**	by splitting ’s’ using the character ’c’ as a delimiter. The array
**	must be ended by a NULL pointer.
*/

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	char	**mem;
	size_t	var[4];

	var[0] = ft_wordcount(s, c);
	mem = malloc(sizeof(char *) * (var[0] + 1));
	if (!s || !mem)
		return (NULL);
	var[1] = 0;
	var[3] = 0;
	while (var[1] < var[0])
	{
		while (s[var[3]] == c)
			var[3]++;
		var[2] = 0;
		while (s[var[3] + var[2]] != c && s[var[3] + var[2]])
			var[2]++;
		mem[var[1]] = malloc(sizeof(char) * (var[2] + 1));
		if (!mem[var[1]])
			return (NULL);
		ft_memcpy(mem[var[1]], s + var[3], var[2]);
		mem[var[1]++][var[2]] = 0;
		var[3] += var[2];
	}
	mem[var[1]] = NULL;
	return (mem);
}
