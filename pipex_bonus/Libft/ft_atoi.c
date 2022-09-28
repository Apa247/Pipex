/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:39:13 by daparici          #+#    #+#             */
/*   Updated: 2022/06/23 13:36:59 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int		valor;
	int							signo;
	unsigned int				i;

	i = 0;
	signo = 1;
	valor = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -signo;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		valor = valor * 10 + (str[i] - '0');
		if (valor >= 9223372036854775807 && signo == 1)
			return (-1);
		if (valor > 9223372036854775807 && signo == -1)
			return (0);
		i++;
	}
	return ((int)(valor * signo));
}

// int main()
// {
// 	char *s = "2147483648";

// 	printf("%d\n", atoi(s));
// 	printf("%d\n", ft_atoi(s));
// 	return (0);
// }
