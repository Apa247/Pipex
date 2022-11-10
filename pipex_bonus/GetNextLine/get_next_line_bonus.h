/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:14:41 by daparici          #+#    #+#             */
/*   Updated: 2022/04/27 17:10:41 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>  

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *res, char *copy);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*copystr(int fd, char *res);
char	*ft_getreserv(char *res);
char	*ft_getline(char *res);

#endif