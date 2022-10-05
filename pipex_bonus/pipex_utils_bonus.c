/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:53:28 by daparici          #+#    #+#             */
/*   Updated: 2022/09/29 20:58:31 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	msg_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
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
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*find_cmd(char *cmd, char **path)
{
	char	*tmp;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		tmp = ft_strjoin(tmp, cmd);
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		path++;
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