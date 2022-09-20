/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:50:07 by daparici          #+#    #+#             */
/*   Updated: 2022/04/05 08:42:21 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numberstr(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			n++;
	}
	return (n);
}

static char	**ft_cuerpo(char **dest, char const *s, char c, size_t n)
{
	size_t	pos;
	size_t	t;
	size_t	inicio;

	t = -1;
	inicio = 0;
	pos = 0;
	while (++t < n)
	{	
		while (s[pos] == c)
			pos++;
		inicio = pos;
		while (s[pos] != c && s[pos])
			pos++;
		dest[t] = ft_substr(s, inicio, (pos - inicio));
		if (!dest[t])
		{
			while (t >= 0)
				free(dest[t--]);
			free(dest);
			return (0);
		}
	}
	dest[t] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	n;

	if (!s)
		return (0);
	n = ft_numberstr(s, c);
	dest = ft_calloc(n + 1, sizeof(char *));
	if (!dest)
		return (0);
	ft_cuerpo(dest, s, c, n);
	return (dest);
}
