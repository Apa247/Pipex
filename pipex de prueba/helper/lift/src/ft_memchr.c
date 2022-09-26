/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:04:47 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/17 14:42:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				cnt;
	const unsigned char	*s_str;

	cnt = 0;
	s_str = s;
	while (cnt < n && s_str[cnt] != (unsigned char)c)
		cnt++;
	if (cnt == n)
		return (NULL);
	else
		return ((void *)&s_str[cnt]);
}
