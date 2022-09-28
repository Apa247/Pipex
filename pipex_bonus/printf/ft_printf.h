/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:52:28 by daparici          #+#    #+#             */
/*   Updated: 2022/09/13 14:34:00 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_printhex(unsigned long long c, char *base, int *len);
void	ft_printadress(unsigned long long c, int *len, char pos);
void	ft_printnbr(long n, int *len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_printchar(unsigned char c, int *len);
void	ft_printstr(char *s, int *len);
void	ft_body(va_list ap, const char pos, int *len);
int		ft_printf(const char *str, ...);

#endif