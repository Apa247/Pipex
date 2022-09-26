/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:28:00 by mgonzale          #+#    #+#             */
/*   Updated: 2022/03/29 13:01:00 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinmulti(const char *s1, const char *s2, const char *s3)
{
	char	*ptr;
	char	*sall;

	ptr = ft_strjoin(s1, s2);
	sall = ft_strjoin(ptr, s3);
	free(ptr);
	return (sall);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!(s1) || !(s2))
		return (NULL);
	ptr = malloc(sizeof(*ptr) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(s1)))
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
