/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:27:32 by mgonzale          #+#    #+#             */
/*   Updated: 2022/03/29 12:59:31 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_joinmulti(const char *s1, const char *s2, const char *s3);
char	*ft_strnstr(const char *big, const char *little, size_t len);
#endif
