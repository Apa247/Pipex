/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 18:56:24 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 20:09:35 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns a string representing the
**	signed long integer received as 'n' transformed acording to the
**	base received as 'base' or NULL if the allocation fails.
**	Negative numbers are also handled.
*/

#include "libft.h"

char	*ft_litoa_base(long int n, char *base)
{
	char		ret[66];
	short int	i;
	int			bsize;

	bsize = ft_strlen(base);
	if (!base || bsize < 2)
		return ("Error, no valid base to transform 'n'");
	i = 65;
	ft_bzero(ret, 66 * sizeof(char));
	if (n < 0)
	{
		ret[0] = '-';
		ret[--i] = base[-(n % bsize)];
		n = -(n / bsize);
	}
	while (n % bsize || n / bsize)
	{
		ret[--i] = base[n % bsize];
		n /= bsize;
	}
	if (ret[0] == '-')
		ret[--i] = '-';
	else if (i == 65)
		ret[--i] = '0';
	return (ft_strdup(&ret[i]));
}
