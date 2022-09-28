/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:59:05 by daparici          #+#    #+#             */
/*   Updated: 2022/03/30 21:39:54 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (*s == '\0' && c == '\0')
		return ((char *)&s[i]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

/*int main (void)
{
	const char *s = "";

	puts(strchr(s, '\0'));
	puts(ft_strchr(s, '\0'));
	return (0);
}*/
