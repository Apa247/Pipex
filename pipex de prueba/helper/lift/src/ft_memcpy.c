/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:50:25 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/14 16:12:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		cnt;
	char		*str_dst;
	const char	*str_src;

	cnt = 0;
	str_dst = dst;
	str_src = src;
	if (dst != src)
	{
		while (cnt < n)
		{
			*str_dst = *str_src;
			cnt++;
			str_dst++;
			str_src++;
		}
	}
	return (dst);
}
