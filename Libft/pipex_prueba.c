/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_prueba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:28:15 by daparici          #+#    #+#             */
/*   Updated: 2022/09/26 19:36:26 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <xlocale.h>
/* malloc, free, exit */
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
//# include "./GetNextLine/get_next_line.h"
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
/* para write, read, close, access, pipe, dup2, dup, execve, fork */
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
/* waitpid, wait */
#include <sys/wait.h>

char	*ft_strjoin(char *s1, const char *s2);
char	*find_cm(char *cmd, char **path);
static size_t	ft_numberstr(const char *s, char c);
static char	**ft_cuerpo(char **dest, char const *s, char c, size_t n);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*find_paths(char **envp);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!*s && !s)
		return (0);
	while (s[len])
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return ((char *)str);
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{	
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		str[i] = s2[i2];
		i++;
		i2++;
	}
	str[i] = '\0';
	return (str);
}

char	*find_cm(char *cmd, char **path)
{
	char	*tmp;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		tmp = ft_strjoin(tmp, cmd);
		if (access(tmp, R_OK))
			return (tmp);
		free(tmp);
		path++;
	}
	return (NULL);
}

static size_t	ft_numberstr(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			n++;
	}
	return (n);
}

static char	**ft_cuerpo(char **dest, char const *s, char c, size_t n)
{
	size_t	pos;
	size_t	t;
	size_t	inicio;

	t = -1;
	inicio = 0;
	pos = 0;
	while (++t < n)
	{	
		while (s[pos] == c)
			pos++;
		inicio = pos;
		while (s[pos] != c && s[pos])
			pos++;
		dest[t] = ft_substr(s, inicio, (pos - inicio));
		if (!dest[t])
		{
			while (t >= 0)
				free(dest[t--]);
			free(dest);
			return (0);
		}
	}
	dest[t] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	n;

	if (!s)
		return (0);
	n = ft_numberstr(s, c);
	dest = ft_calloc(n + 1, sizeof(char *));
	if (!dest)
		return (0);
	ft_cuerpo(dest, s, c, n);
	return (dest);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] && str2[i] != '\0') && str1[i] == str2[i] && i < n - 1)
		i++;
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}

char	*find_paths(char **envp)
{	
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	char *path;
	char **cmd_path;
	char **cmd_arg;
	char *cmd;

	path = find_paths(envp);
	cmd_path = ft_split(path, ':');
	cmd_arg = ft_split(argv[1], ' ');
	cmd = find_cm(cmd_arg[0], cmd_path);
	execve(cmd, cmd_arg, envp);
	printf("%i\n", execve(cmd, cmd_arg, envp));
	return (0);
}