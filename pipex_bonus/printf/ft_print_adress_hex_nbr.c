/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress_hex_nbr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:06 by daparici          #+#    #+#             */
/*   Updated: 2022/04/20 20:27:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned long long c, char *base, int *len)
{
	if (c > 15)
		ft_printhex(c / 16, base, len);
	write(1, &base[c % 16], 1);
	(*len)++;
}

void	ft_printadress(unsigned long long c, int *len, char pos)
{
	char	base[17];

	if (pos == 'p' || pos == 'x')
	{
		if (pos == 'p')
		{
			write(1, "0x", 2);
			(*len) += 2;
		}
		ft_strlcpy(base, "0123456789abcdef", 17);
	}
	if (pos == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	ft_printhex(c, base, len);
}

void	ft_printnbr(long n, int *len)
{
	if (n < 0)
	{
		ft_printchar('-', len);
		ft_printnbr(-n, len);
	}
	else if (n < 10)
		ft_printchar(n + '0', len);
	else
	{
		ft_printnbr(n / 10, len);
		ft_printnbr(n % 10, len);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst && !src)
	{
		if (size < 0)
			return (0);
	}
	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
