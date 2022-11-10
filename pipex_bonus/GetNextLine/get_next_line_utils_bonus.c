/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:07:13 by daparici          #+#    #+#             */
/*   Updated: 2022/04/27 17:10:23 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *res, char *copy)
{
	char	*str;
	size_t	i;
	size_t	i2;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
	}
	if (!res || !copy)
		return (NULL);
	str = malloc((ft_strlen(res) + ft_strlen(copy) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	i2 = 0;
	if (res)
		while (res[++i] != '\0')
			str[i] = res[i];
	while (copy[i2] != '\0')
		str[i++] = copy[i2++];
	str[i] = '\0';
	free(res);
	return (str);
}
