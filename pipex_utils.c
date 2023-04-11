/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:39:09 by daparici          #+#    #+#             */
/*   Updated: 2023/04/11 13:13:25 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *msg, int type_error, int cd_error)
{
	if (type_error == 1)
	{
		ft_printf("%s\n", msg);
		exit(1);
	}
}

void	close_parent(int *pipe)
{
	close(pipe[0]);
	waitpid(-1, NULL, 0);
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
		msg_error_cmd(cmd);
	}
	return (NULL);
}
