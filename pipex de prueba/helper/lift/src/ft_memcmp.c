/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:22:53 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/14 13:11:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str_s1;
	const unsigned char	*str_s2;

	str_s1 = s1;
	str_s2 = s2;
	while (n > 0 && *str_s1 == *str_s2)
	{
		str_s1++;
		str_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*str_s1 - *str_s2);
}
