/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:37 by daparici          #+#    #+#             */
/*   Updated: 2022/09/26 20:21:01 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	leaks(void)
// {
// 	system("leaks pipex");
// }

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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	// atexit(leaks);
	pipex = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	pipex->path = find_paths(envp);
	pipex->cmd_path = ft_split(pipex->path, ':');
	if (argc != 5)
		return (msg_error("ERROR: Invalid number of arguments"));
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		return (msg_error("FILE ERROR"));
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		return (msg_error("FILE ERROR"));
	pipe(pipex->pipe);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first_child(pipex, argv, envp);
	close(pipex->pipe[0]);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		second_child(pipex, argv, envp);
	close(pipex->pipe[1]);
	waitpid(-1, NULL, 0);
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
	printf("holaa\n");
	printf("%i\n", execve(pipex->cmd, pipex->cmd_arg, envp));
}

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	close(pipex->pipe[0]);
	if (dup2(pipex->infile, 0) != 0)
		msg_error("Error child 1\n");
	close(pipex->infile);
	if (dup2(pipex->pipe[1], 1) != 0)
		msg_error("Error child 1 dup pipe\n");
	close(pipex->pipe[1]);
	pipex->cmd_arg = ft_split(argv[2], ' ');
	pipex->cmd = find_cmd(pipex->cmd_arg[0], pipex->cmd_path);
	if (!pipex->cmd)
	{
		msg_error("ERROR: comand not found");
		exit(1);
	}
	printf("%s\n", pipex->cmd);
	printf("%s\n", pipex->cmd_arg[0]);
	printf("%s\n", pipex->cmd_arg[1]);
	if (execve(pipex->cmd, pipex->cmd_arg, envp) < 0)
		msg_error("HOLAAAAA");
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
