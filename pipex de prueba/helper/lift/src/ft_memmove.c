/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:17:52 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/28 13:35:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		cnt;
	char		*dst_str;
	const char	*src_str;

	cnt = 0;
	dst_str = dst;
	src_str = src;
	if (src || dst)
	{
		if (src < dst)
			while (len-- > 0)
				dst_str[len] = src_str[len];
		else if (src > dst)
		{
			while (cnt < len)
			{
				dst_str[cnt] = src_str[cnt];
				cnt++;
			}
		}
	}
	return (dst);
}
