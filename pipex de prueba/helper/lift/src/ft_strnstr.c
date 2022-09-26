/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:27:17 by rgallego          #+#    #+#             */
/*   Updated: 2021/09/27 19:08:08 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;

	cnt = 0;
	while (*haystack && needle[cnt] && len)
	{
		cnt = 0;
		while (haystack[cnt] && needle[cnt] && haystack[cnt] == needle[cnt])
			cnt++;
		haystack++;
		len--;
	}
	if (*needle && !needle[cnt] && cnt <= len + 1)
		return ((char *)(haystack - 1));
	else if (!*needle)
		return ((char *)haystack);
	else
		return (NULL);
}
