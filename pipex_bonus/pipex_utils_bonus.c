/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:53:28 by daparici          #+#    #+#             */
/*   Updated: 2022/09/27 20:57:39 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus"

void	msg_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	close_parent(int *pipe)
{
	close(pipe[0]);
	wait(NULL);
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
