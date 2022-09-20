/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:42:37 by daparici          #+#    #+#             */
/*   Updated: 2022/03/29 16:54:47 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	char			*dest;
	int				a;
	int				b;
	unsigned int	start;

	start = 0;
	a = 0;
	if (!set || !s1)
		return (NULL);
	b = ft_strlen(s1) - 1;
	while (s1[a] && ft_strchr(set, s1[a]))
		a++;
	while (ft_strrchr(set, s1[b]) && b >= a)
		b--;
	dest = malloc((b - a + 2) * sizeof(char));
	if (!dest)
		return (0);
	while (a <= b)
		dest[start++] = s1[a++];
	dest[start] = '\0';
	return (dest);
}
/*int main()
{
	const char *s1 = " ";
	const char *set = " ";

	puts(ft_strtrim(s1, set));
	return (0);
}
*/