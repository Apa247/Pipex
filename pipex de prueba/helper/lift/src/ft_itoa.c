/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:56:30 by rgallego          #+#    #+#             */
/*   Updated: 2021/11/12 17:23:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n, unsigned int *aux)
{
	int	len;

	*aux = (unsigned int)n;
	if (n < 0)
	{
		len = 1;
		*aux = n * -1;
	}
	else
		len = 0;
	while (n <= -10 || 10 <= n)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			*n_str;
	unsigned int	aux;
	int				len;

	len = ft_nlen(n, &aux);
	n_str = malloc(sizeof(char) * (len + 1));
	if (n_str)
	{
		n_str[len] = '\0';
		len--;
		while (aux >= 10)
		{
			n_str[len] = '0' + (aux % 10);
			aux /= 10;
			len--;
		}
		n_str[len] = '0' + aux;
		if (len)
			n_str[0] = '-';
	}
	return (n_str);
}
