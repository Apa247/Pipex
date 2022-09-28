/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:55:49 by daparici          #+#    #+#             */
/*   Updated: 2022/09/28 18:15:30 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	process;

	process = argc - 3;
	if (argc < 5)
		msg_error("Error number of parameters");
	recursive_process(process, argc, argv, envp);
	return (0);
}

void	recursive_process(int process, int argc, char **argv, char **envp)
{
	int	tub[2];
	int	pid;

	pipe(tub);
	pid = fork();
	if (pid == 0)
	{
		if (process == 2)
		{
			first_child(tub, argv, envp);
			process++;
			recursive_process(process, argc, argv, envp);
		}
		if (process < argc - 2)
		{
			mid_process(process, tub, argv, envp);
			printf("hola\n");
			process++;
			recursive_process(process, argc, argv, envp);
		}
		if (process == argc - 2)
		{
			last_child(process, tub, argv, envp);
		}
	}
}

void	first_child(int *pipe, char **argv, char **envp)
{
	char	*path;
	char	**ruts;
	char	**cmd_arg;
	char	*cmd;
	int		file;

	close(pipe[0]);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		msg_error("Error in first file");
	dup2(file, 0);
	close(file);
	dup2(pipe[1], 1);
	close(pipe[1]);
	path = find_paths(envp);
	ruts = ft_split(path, ':');
	cmd_arg = ft_split(argv[2], ' ');
	cmd = find_cmd(cmd_arg[0], ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}

void	mid_process(int pos, int *pipe, char **argv, char **envp)
{
	char	*path;
	char	**ruts;
	char	**cmd_arg;
	char	*cmd;

	dup2(pipe[0], 0);
	close(pipe[0]);
	dup2(pipe[1], 1);
	printf("hola\n");
	close(pipe[1]);
	path = find_paths(envp);
	ruts = ft_split(path, ':');
	cmd_arg = ft_split(argv[pos], ' ');
	cmd = find_cmd(cmd_arg[0], ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}

void	last_child(int pos, int *pipe, char **argv, char **envp)
{
	char	*path;
	char	**ruts;
	char	**cmd_arg;
	char	*cmd;
	int		file;

	file = open(argv[4], O_WRONLY);
	if (file < 0)
		msg_error("Error in first file");
	dup2(pipe[0], 0);
	close(pipe[0]);
	dup2(file, 1);
	close(file);
	path = find_paths(envp);
	ruts = ft_split(path, ':');
	cmd_arg = ft_split(argv[pos], ' ');
	cmd = find_cmd(cmd_arg[0], ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}