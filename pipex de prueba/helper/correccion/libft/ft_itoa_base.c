/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 18:56:24 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/05 20:10:00 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns a string representing the
**	signed long integer received as 'n' transformed acording to the
**	base received as 'base' or NULL if the allocation fails.
**	Negative numbers are also handled.
*/

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char		ret[34];
	short int	i;
	int			bsize;

	bsize = ft_strlen(base);
	if (!base || bsize < 2)
		return ("Error, no valid base to transform 'n'");
	i = 33;
	ft_bzero(ret, 34 * sizeof(char));
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
	else if (i == 33)
		ret[--i] = '0';
	return (ft_strdup(&ret[i]));
}
