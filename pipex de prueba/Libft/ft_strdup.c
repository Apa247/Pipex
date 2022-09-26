/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:24:33 by mgonzale          #+#    #+#             */
/*   Updated: 2021/07/14 14:41:45 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		x;
	char	*str;

	str = malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	x = -1;
	while (s[++x] != '\0')
		str[x] = s[x];
	str[x] = '\0';
	return (str);
}
