/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:37 by daparici          #+#    #+#             */
/*   Updated: 2022/09/25 21:20:18 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	leaks(void)
{
	system("leaks pipex");
}

int	msg_error(char *msg)
{
	ft_printf("%s\n", msg);
	return (1);
}

char	*find_paths(char **envp)
{	
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	atexit(leaks);
	pipex = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	pipex->path = find_paths(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (argc != 5)
		return (msg_error("ERROR: Invalid number of arguments"));
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		return (msg_error("FILE ERROR"));
	pipe(pipex->pipe);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		return (msg_error("ERROR: fail when create first child process"));
	if (pipex->pid1 == 0)
		first_child(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		return (msg_error("ERROR: fail when create second child process"));
	if (pipex->pid2 == 0)
		second_child(pipex, argv, envp);
	waitpid(pipex->pid1, NULL, 0);
	return (0);
}

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe[0]);
	dup2(pipex->infile, 0);
	dup2(pipex->pipe[1], 1);
	pipex->cmd_arg = ft_split(argv[2], ' ');
	pipex->cmd = find_cmd(pipex->cmd_arg[0], pipex->cmd_path);
	if (!pipex->cmd)
	{
		free_child(pipex);
		msg_error("ERROR: comand not found");
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_arg, envp);
}

char	*find_cmd(char *cmd, char **path)
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

void	free_child(t_pipex *pipex)
{
	while (*(pipex->cmd_arg))
	{
		free(*(pipex->cmd_arg));
		(pipex->cmd_arg)++;
	}
	free(pipex->cmd_arg);
	while (*(pipex->cmd_path))
	{
		free(*(pipex->cmd_path));
		(pipex->cmd_path)++;
	}
	free(pipex->cmd_path);
	free(pipex->cmd);
}
