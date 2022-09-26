/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:47:20 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 10:55:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		cnt;

	res = NULL;
	cnt = 0;
	if (s)
	{
		res = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (res)
		{
			while (s[cnt])
			{
				res[cnt] = f(cnt, s[cnt]);
				cnt++;
			}
			res[cnt] = '\0';
		}
	}
	return (res);
}
