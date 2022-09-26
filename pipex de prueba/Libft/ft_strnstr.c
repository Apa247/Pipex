/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:04:25 by mgonzale          #+#    #+#             */
/*   Updated: 2021/03/01 20:20:52 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] != '\0')
				j++;
			if (little[j] == '\0' && (i + j) <= len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
