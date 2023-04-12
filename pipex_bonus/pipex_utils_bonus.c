/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:53:28 by daparici          #+#    #+#             */
/*   Updated: 2023/04/12 13:08:30 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	msg_error(char *msg, int type_error, int cd_error)
{
	if (type_error == 1)
	{
		perror(msg);
		exit(cd_error);
	}
	if (type_error == 2)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
}

char	**envp_copy(char **envp)
{
	char	**envp_cp;
	int		x;
	int		y;

	x = 0;
	envp_cp = malloc(sizeof(char *) * (ft_strlen_cp(envp) + 1));
	if (!envp_cp)
		return (NULL);
	while (envp[x])
	{
		y = 0;
		envp_cp[x] = (char *)malloc(sizeof(char) * (ft_strlen(envp[x]) + 1));
		if (!envp_cp[x])
			return (NULL);
		while (envp[x][y])
		{
			envp_cp[x][y] = envp[x][y];
			y++;
		}
		envp_cp[x][y] = '\0';
		x++;
	}
	envp_cp[x] = NULL;
	return (envp_cp);
}

char	*find_paths(char **envp)
{	
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp)
		return (*envp + 5);
	else
		return (NULL);
}

char	*find_cmd(char *cmd, char **path)
{
	char	*tmp;

	if (!access(cmd, X_OK))
		return (cmd);
	if (path)
	{
		while (*path)
		{
			tmp = ft_strjoin(*path, "/");
			tmp = ft_strjoin(tmp, cmd);
			if (!access(tmp, X_OK))
				return (tmp);
			free(tmp);
			path++;
		}
		msg_error(cmd, 2, 127);
	}
	return (NULL);
}

size_t	ft_strlen_cp(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{	
		i++;
	}
	return (i);
}

size_t	ft_strlen_pid(int *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{	
		i++;
	}
	return (i);
}