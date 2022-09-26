/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:05:05 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/14 12:41:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (dstsize)
	{
		while (*dst && dstsize > 0)
		{
			dst++;
			len++;
			dstsize--;
		}
		if (dstsize)
		{
			while (*src && dstsize > 1)
			{
				*dst = *src;
				dst++;
				src++;
				dstsize--;
			}
			*dst = '\0';
		}
	}
	return (len);
}
