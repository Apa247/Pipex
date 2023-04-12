/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:18:30 by daparici          #+#    #+#             */
/*   Updated: 2023/04/12 11:37:36 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	leaks(void)
// {
// 	system("leaks pipex");
// }

int	main(int argc, char **argv, char **envp)
{
	int	tub[2];
	int	pid;

	// atexit(leaks);
	if (argc != 5)
		msg_error("ERROR: Invalid number of arguments", ARG_ERROR, errno);
	pipe(tub);
	pid = fork();
	if (pid == -1)
		msg_error("Error in first process", PROC_ERROR, errno);
	if (pid == 0)
		first_child(tub, argv, envp);
	close(tub[1]);
	pid = fork();
	if (pid == -1)
		msg_error("Error in second process", PROC_ERROR, errno);
	if (pid == 0)
		second_child(tub, argv, envp);
	close_parent(tub);
	return (0);
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
		msg_error("Error in first file", FILE_ERROR, errno);
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

void	second_child(int *pipe, char **argv, char **envp)
{
	char	*path;
	char	**ruts;
	char	**cmd_arg;
	char	*cmd;
	int		file;

	file = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | O_APPEND);
	if (file < 0)
		msg_error("Error in first file");
	dup2(pipe[0], 0);
	close(pipe[0]);
	dup2(file, 1);
	close(file);
	path = find_paths(envp);
	ruts = ft_split(path, ':');
	cmd_arg = ft_split(argv[3], ' ');
	cmd = find_cmd(cmd_arg[0], ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}
