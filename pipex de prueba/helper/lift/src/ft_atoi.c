/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:26:28 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/09 13:55:36 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * function which receives a string and transforms it to int.
 * INPUT:	const char *s
 * OUTPUT:	int	:	N	the string represents a number in int's range
 *					0	the number represented is lower than INT_MIN
 *					-1	the number is greater than INT_MAX
 */

int	ft_atoi(const char *s)
{
	int					sign;
	unsigned long long	num;

	sign = 1;
	num = 0;
	while (*s && (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
			|| *s == '\r' || *s == ' '))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && '0' <= *s && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	if (sign == 1 && num > LLONG_MAX)
		return (-1);
	else if (sign == -1 && num > LLONG_MAX)
		return (0);
	else
		return (sign * num);
}
