/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:14:28 by daparici          #+#    #+#             */
/*   Updated: 2022/06/20 19:01:58 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getreserv(char *res)
{
	char	*copy;
	int		k;
	int		i;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	copy = (char *)malloc((ft_strlen(res) - i + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i++;
	k = 0;
	while (res[i])
		copy[k++] = res[i++];
	copy[k] = '\0';
	free(res);
	return (copy);
}

char	*ft_copystr(int fd, char *res)
{
	char	*copy;
	int		len;

	copy = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	len = 1;
	while (!ft_strchr(res, '\n') && len != 0)
	{
		len = read(fd, copy, BUFFER_SIZE);
		if (len == -1)
		{
			free(copy);
			return (NULL);
		}
		copy[len] = '\0';
		res = ft_strjoin(res, copy);
	}
	free(copy);
	return (res);
}

char	*ft_getline(char *res)
{
	char	*line;
	int		i;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*res[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res[fd] = ft_copystr(fd, res[fd]);
	if (!res[fd])
		return (NULL);
	line = ft_getline(res[fd]);
	res[fd] = ft_getreserv(res[fd]);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnl.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("primera linea:%s", line);
	line = get_next_line(fd);
	printf("segunda linea:%s", line);
	line = get_next_line(fd);
	printf("tercera linea:%s", line);
	close(fd);
	fd = open("gnl.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("cuarta linea:%s", line);
	line = get_next_line(fd);
	printf("quinta linea:%s\n", line);
	close(fd);
	return (0);
}
