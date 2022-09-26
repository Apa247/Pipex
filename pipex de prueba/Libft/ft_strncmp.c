/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:05:14 by mgonzale          #+#    #+#             */
/*   Updated: 2021/03/03 20:32:38 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	while ((aux1[i] != '\0' || aux2[i] != '\0') && i < n)
	{
		if (aux1[i] != aux2[i] && (aux1[i] != '\0' && aux2[i] == '\0'))
			return (aux1[i]);
		else if (aux1[i] != aux2[i] && (aux1[i] == '\0' && aux2[i] != '\0'))
			return (aux2[i] * -1);
		else if (aux1[i] != aux2[i] && (aux1[i] != '\0' && aux2[i] != '\0'))
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}
