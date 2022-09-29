/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:55:49 by daparici          #+#    #+#             */
/*   Updated: 2022/09/29 21:39:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		x;

	pipex = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	x = 0;
	pipex->process = 2;
	pipex->argc_cp = argc;
	pipex->x = 0;
	pipex->tub = malloc((argc - 4) * sizeof(int *));
	while (x < argc - 4)
	{
		pipex->tub[x] = ft_calloc(sizeof(int), 4);
		x++;
	}
	if (argc < 5)
		msg_error("Error number of parameters");
	x = 0;
	while (x < argc - 4)
	{
		pipe(pipex->tub[x]);
		x++;
	}
	x = 0;
	pipex->path = find_paths(envp);
	pipex->ruts = ft_split(pipex->path, ':');
	recursive_process(pipex, argv, envp);
	while (x < argc - 3)
		waitpid(-1, NULL, 0);
	return (0);
}

void	recursive_process(t_pipex *pipex, char **argv, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (pipex->process == 2)
		{
			first_child(pipex, argv, envp);
			printf("hola\n");
		}
		if (pipex->process < pipex->argc_cp - 2)
		{
			printf("hola2\n");
			mid_process(pipex, argv, envp);
		}
		if (pipex->process == pipex->argc_cp - 2)
		{
			printf("hola3\n");
			last_child(pipex, argv, envp);
		}
	}
	else
	{
		if (pipex->process < pipex->argc_cp - 2)
		{
			pipex->process++;
			pipex->x++;
			printf("holaaaa\n");
			recursive_process(pipex, argv, envp);
		}
	}
}

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd;
	int		file;

	close(pipex->tub[0][0]);
	file = open(argv[2], O_RDONLY);
	if (file < 0)
		msg_error("Error in first file");
	dup2(pipex->file, 0);
	close(pipex->file);
	dup2(pipex->tub[0][1], 1);
	close(pipex->tub[0][1]);
	printf("hola\n");
	cmd_arg = ft_split(argv[2], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}

void	mid_process(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd;

	close(pipex->tub[pipex->x - 1][1]);
	close(pipex->tub[pipex->x][0]);
	dup2(pipex->tub[pipex->x - 1][0], 0);
	close(pipex->tub[pipex->x - 1][0]);
	dup2(pipex->tub[pipex->x][1], 1);
	printf("hola\n");
	close(pipex->tub[pipex->x][1]);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}

void	last_child(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd;
	int		file;

	file = open(argv[pipex->argc_cp - 2], O_WRONLY);
	if (file < 0)
		msg_error("Error in second file");
	dup2(pipex->tub[pipex->x][0], 0);
	close(pipex->tub[pipex->x][0]);
	dup2(file, 1);
	close(file);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, envp);
}