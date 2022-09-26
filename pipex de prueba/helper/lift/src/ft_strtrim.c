/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:42:12 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 17:07:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*s;

	if (s1)
	{
		len = ft_strlen(s1) + 1;
		while (*s1 && ft_strchr(set, *s1))
		{
			s1++;
			len--;
		}
		while (len > 1 && ft_strchr(set, s1[len - 2]))
			len--;
		s = malloc(sizeof(char) * (len));
		if (s)
			(void)ft_strlcpy(s, s1, len);
		return (s);
	}
	else
		return (NULL);
}
