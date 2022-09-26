/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:12:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/10 19:43:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;

	if (s)
	{
		s_len = ft_strlen(s);
		if (s_len < start)
			sub_str = ft_strdup("");
		else
		{
			if (s_len < (len + start))
				len = ft_strlen(&s[start]);
			sub_str = malloc(sizeof(char) * (len + 1));
			if (sub_str)
				(void)ft_strlcpy(sub_str, &s[start], len + 1);
		}
		return (sub_str);
	}
	else
		return (NULL);
}
