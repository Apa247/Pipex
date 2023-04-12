/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/04/12 13:05:54 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac)
{
	char	**cmd_arg;
	char	*cmd;

	close(tub_pre[0]);
	close(tub_pre[1]);
	close(tub_ac[0]);
	if (dup2(pipex->infile, 0) < 0)
		msg_error("Bad file descriptor", 1, errno);
	close(pipex->infile);
	if (dup2(tub_ac[1], 1) < 0)
		msg_error("Bad file descriptor", 1, errno);
	close(tub_ac[1]);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (!execve(cmd, cmd_arg, pipex->envp_cp))
		msg_error("Command not found", 2, 127);
}

void	mid_process(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac)
{
	char	**cmd_arg;
	char	*cmd;

	close(tub_pre[1]);
	close(tub_ac[0]);
	if (dup2(tub_pre[0], 0) < 0)
		msg_error("Bad file descriptor", 1, errno);
	close(tub_pre[0]);
	if (dup2(tub_ac[1], 1) < 0)
		msg_error("Bad file descriptor ", 1, errno);
	close(tub_ac[1]);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (execve(cmd, cmd_arg, pipex->envp_cp) < 0)
		msg_error("Command not found", 2, 127);
}

void	last_child(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac)
{
	char	**cmd_arg;
	char	*cmd;
	int		outfile;

	outfile = open(argv[pipex->argc_cp - 1], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | O_APPEND);
	if (outfile < 0)
		msg_error("Bad file descriptor", 1, errno);
	close(tub_ac[0]);
	close(tub_ac[1]);
	close(tub_pre[1]);
	if (dup2(tub_pre[0], 0) < 0)
		msg_error("Bad file descriptor", 1, errno);
	close(tub_pre[0]);
	if (dup2(outfile, 1) < 0)
		msg_error("Bad file descriptor", 1, errno);
	close(outfile);
	cmd_arg = ft_split(argv[pipex->process], ' ');
	cmd = find_cmd(cmd_arg[0], pipex->ruts);
	if (execve(cmd, cmd_arg, pipex->envp_cp) < 0)
		msg_error("Command not found", 2, 127);
}
