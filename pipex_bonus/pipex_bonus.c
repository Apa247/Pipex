/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:55:49 by daparici          #+#    #+#             */
/*   Updated: 2022/10/06 15:45:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static void	leaks(void)
// {
// 	system("leaks pipex");
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		tub[2];

	//atexit(leaks);
	if (argc < 5)
		msg_error("Error number of parameters");
	if (!*envp)
		msg_error("Command not found");
	pipex = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	pipex->process = 2;
	pipex->argc_cp = argc;
	pipex->envp_cp = envp_copy(envp);
	// while (*(pipex->envp_cp))
	// {
	// 	printf("%s\n", *(pipex->envp_cp));
	// 	(pipex->envp_cp)++;
	// }
	// while (*envp)
	// {
	// 	printf("%s\n", *envp);
	// 	envp++;
	// }
	pipex->path = find_paths(envp);
	pipex->ruts = ft_split(pipex->path, ':');
	pipe(tub);
	rec_process(tub, pipex, argv);
	close(tub[0]);
	close(tub[1]);
	while (*(pipex->envp_cp))
	{
		free(*(pipex->envp_cp));
		(pipex->envp_cp)++;
	}
	while (*(pipex->ruts))
	{
		free(*(pipex->ruts));
		(pipex->ruts)++;
	}
	waitpid(-1, NULL, 0);
	exit(0);
}

void	rec_process(int *tub_pre, t_pipex *pipex, char **argv)
{
	int		pid;
	int		tub_ac[2];

	pipe(tub_ac);
	pid = fork();
	if (pid == 0)
	{
		if (pipex->process == 2)
			first_child(pipex, argv, tub_pre, tub_ac);
		if (pipex->process < pipex->argc_cp - 2)
			mid_process(pipex, argv, tub_pre, tub_ac);
		if (pipex->process == pipex->argc_cp - 2)
			last_child(pipex, argv, tub_pre, tub_ac);
	}
	else
	{
		if (pipex->process < pipex->argc_cp - 2)
		{
			close(tub_pre[0]);
			close(tub_pre[1]);
			pipex->process++;
			rec_process(tub_ac, pipex, argv);
		}
	}
}

void	first_child(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac)
{
	char	**cmd_arg;
	char	*cmd;
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		msg_error("Error in first file");
	close(tub_pre[0]);
	close(tub_pre[1]);
	close(tub_ac[0]);
	dup2(infile, 0);
	close(infile);
	dup2(tub_ac[1], 1);
	close(tub_ac[1]);
	cmd_arg = ft_split(argv[2], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, pipex->envp_cp);
}

void	mid_process(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac)
{
	char	**cmd_arg;
	char	*cmd;

	close(tub_pre[1]);
	close(tub_ac[0]);
	dup2(tub_pre[0], 0);
	close(tub_pre[0]);
	dup2(tub_ac[1], 1);
	close(tub_ac[1]);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, pipex->envp_cp);
}

void	last_child(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac)
{
	char	**cmd_arg;
	char	*cmd;
	int		outfile;

	outfile = open(argv[pipex->argc_cp - 1], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (outfile < 0)
		msg_error("Error in second file");
	close(tub_ac[0]);
	close(tub_ac[1]);
	close(tub_pre[1]);
	dup2(tub_pre[0], 0);
	close(tub_pre[0]);
	dup2(outfile, 1);
	close(outfile);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!cmd)
		msg_error("ERROR: comand not found");
	execve(cmd, cmd_arg, pipex->envp_cp);
}
