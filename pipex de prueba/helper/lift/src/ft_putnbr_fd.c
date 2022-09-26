/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:53:53 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/23 09:36:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_aux(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_fd_aux(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	aux;

	aux = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux = n * -1;
	}
	ft_putnbr_fd_aux(aux, fd);
}
