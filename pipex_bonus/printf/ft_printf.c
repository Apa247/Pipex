/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:26:34 by daparici          #+#    #+#             */
/*   Updated: 2022/09/13 13:34:10 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(unsigned char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_printstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		(*len)++;
	}
}

void	ft_body(va_list ap, const char pos, int *len)
{
	if (pos == 'c')
		ft_printchar(va_arg(ap, int), len);
	if (pos == 's')
		ft_printstr(va_arg(ap, char *), len);
	if (pos == 'p')
		ft_printadress((unsigned long long)va_arg(ap, void *), len, pos);
	if (pos == 'x' || pos == 'X')
		ft_printadress((unsigned int)va_arg(ap, void *), len, pos);
	if (pos == 'd' || pos == 'i')
		ft_printnbr(va_arg(ap, int), len);
	if (pos == 'u')
		ft_printnbr(va_arg(ap, unsigned int), len);
}

int	ft_printf(const char *str, ...)
{
	size_t			i;
	int				len;
	va_list			ap;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_printchar(str[i], &len);
			else
				ft_body(ap, str[i], &len);
		}
		else
			ft_printchar(str[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}

// int main()
// {
// 	//int	g;
// 	int len;

// 	//g = 3;
// 	//ft_printf("hola papu\n%x\n", 0);
// 	//printf("hola papu\n%x\n", 0);
// 	len = ft_printf("hola papu\n%x\n", 2147483646);
// 	//printf("%p", &g);
// 	 if (len == printf("hola papu\n%x\n", 2147483646))
// 	 	write(1, "bien", 4);
// 	 else
// 	 	write(1, "mal", 3);
// 	return (0);
// }
