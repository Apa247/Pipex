/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:13:42 by daparici          #+#    #+#             */
/*   Updated: 2022/09/20 13:28:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_modulos(int n)
{
	int				i;
	unsigned int	m;

	i = 0;
	m = 0;
	if (n > 0)
		m = n;
	if (n <= 0)
	{
		m = n * -1;
		i++;
	}
	while (m > 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

static char	*ft_str(char *dest, unsigned int m, int i)
{
	while (i >= 0)
	{
		dest[i--] = (m % 10) + 48;
		m = m / 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char			*dest;
	int				i;
	int				signo;
	unsigned int	m;

	signo = 0;
	i = ft_modulos(n);
	if (n >= 0)
	m = n;
	if (n < 0)
	{
		signo = 1;
		m = n * -1;
	}
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	if (n == 0)
		dest[0] = '0';
	dest[i--] = '\0';
	ft_str(dest, m, i);
	if (signo == 1)
		dest[0] = '-';
	return (dest);
}
/*
int	main()
{
	int	n = 0;
	puts(ft_itoa(n));
	return (0);
}*/