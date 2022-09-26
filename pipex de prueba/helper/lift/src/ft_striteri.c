/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:35:03 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/16 11:26:22 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	cnt;

	cnt = 0;
	if (s)
	{
		while (s[cnt])
		{
			f(cnt, &s[cnt]);
			cnt++;
		}
	}
}
