/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:51:39 by daparici          #+#    #+#             */
/*   Updated: 2022/04/18 20:35:59 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
