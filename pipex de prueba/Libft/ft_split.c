/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:48:45 by mgonzale          #+#    #+#             */
/*   Updated: 2022/02/18 19:07:16 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chunks(const char *s, char c)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (i <= ft_strlen(s))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (x);
		if (s[i] != c && s[i] != '\0')
			x = x + 1;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (x);
}

int	wordlen(const char *s, char c, int index)
{
	int	i;

	i = 0;
	while (s[index] != c && s[index] != '\0')
	{
		i = i + 1;
		index++;
	}
	return (i);
}

void	ft_write(char *cad, int z, const char *s, char c)
{
	int		k;
	int		y;

	k = 0;
	y = z;
	while (y < (z + wordlen(s, c, z)))
		cad[k++] = (char)s[y++];
	cad[k] = '\0';
}

char	**ft_free(char **tab, const char *s, char c)
{
	int		y;

	y = chunks(s, c);
	while (y >= 0)
	{
		free(*tab + y);
		y--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (chunks(s, c) + 1));
	if (!tab)
		return (NULL);
	while (j < chunks(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[j] = malloc(sizeof(char) * (wordlen(s, c, i) + 1));
			if (!tab[j])
				return (ft_free(tab, s, c));
			ft_write(tab[j], i, s, c);
			i = i + wordlen(s, c, i);
		}
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
