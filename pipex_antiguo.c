/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_antiguo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:37 by daparici          #+#    #+#             */
/*   Updated: 2022/09/27 19:47:42 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	leaks(void)
// {
// 	system("leaks pipex");
// }

void	msg_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

char	*find_paths(char **envp)
{	
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_parent(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	while (*(pipex->cmd_path))
	{
		free(*(pipex->cmd_path));
		(pipex->cmd_path)++;
	}
}

void	open_files(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		msg_error("Infile error");
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		msg_error("Outfile error");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	// atexit(leaks);
	pipex = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	pipex = params_init(pipex);
	if (argc != 5)
		msg_error("ERROR: Invalid number of arguments");
	pipex->path = find_paths(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	open_files(pipex, argv);
	pipe(pipex->pipe);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first_child(pipex, argv, envp);
	close(pipex->pipe[1]);
	printf("holaaaaaa\n");
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		second_child(pipex, argv, envp);
	close(pipex->pipe[0]);
	wait(NULL);
	waitpid(-1, NULL, 0);
	close_parent(pipex);
	return (0);
}

void	second_child(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe[1]);
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[0]);
	dup2(pipex->outfile, 1);
	close(pipex->outfile);
	pipex->cmd_arg = ft_split(argv[3], ' ');
	pipex->cmd = find_cmd(pipex->cmd_arg[0], pipex->cmd_path);
	if (!pipex->cmd)
	{
		msg_error("ERROR: comand not found");
		exit(1);
	}
	// printf("holaa\n");
	execve(pipex->cmd, pipex->cmd_arg, envp);
}

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe[0]);
	dup2(pipex->infile, 0);
	close(pipex->infile);
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[1]);
	pipex->cmd_arg = ft_split(argv[2], ' ');
	pipex->cmd = find_cmd(pipex->cmd_arg[0], pipex->cmd_path);
	printf("%s\n", pipex->cmd);
	printf("%s\n", pipex->cmd_arg[0]);
	if (!pipex->cmd)
	{
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
		if (access(tmp, X_OK))
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
	free(pipex->cmd);
}
