/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:19:19 by mgonzale          #+#    #+#             */
/*   Updated: 2022/09/26 20:16:36 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_closeandwait(int	*fd)
{
	close(fd[FD_R]);
	wait(NULL);
	waitpid(-1, NULL, 0);
}

char	*ft_getcmd(char *cmd, char**ruts)
{
	int		q;
	char	*cmdconcat;

	q = 0;
	while (cmd[q] && cmd[q] != '/')
		q++;
	if (cmd[q] == '\0')
	{
		q = 0;
		cmdconcat = ft_joinmulti(ruts[q], "/", cmd);
		while (ruts[q] && cmdconcat && access(cmdconcat, X_OK))
		{
			free(cmdconcat);
			q++;
			cmdconcat = ft_joinmulti(ruts[q], "/", cmd);
		}
		return (cmdconcat);
	}
	return (cmd);
}

void	ft_startproces(int *fd, char **argv, char **envp)
{
	char	**ruts;
	char	**cmd_flags;
	char	*cmd_basic;
	int		file_fd;

	close(fd[FD_R]);
	file_fd = open(argv[1], O_RDONLY);
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	dup2(fd[FD_W], STDOUT_FILENO);
	close(fd[FD_W]);
	file_fd = 0;
	while (envp[file_fd] && !ft_strnstr(envp[file_fd], "PATH=", 5))
		file_fd++;
	cmd_flags = ft_split(argv[2], ' ');
	ruts = ft_split(&envp[file_fd][5], ':');
	cmd_basic = ft_getcmd(cmd_flags[0], ruts);
	execve(cmd_basic, cmd_flags, envp);
}

void	ft_nextproces(int *fd, char **argv, char **envp)
{
	char	**ruts;
	char	**cmd_flags;
	char	*cmd_basic;
	int		file_fd;

	close(fd[FD_W]);
	file_fd = open(argv[4], O_WRONLY | O_TRUNC | O_APPEND);
	dup2(fd[FD_R], STDIN_FILENO);
	close(fd[FD_R]);
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	file_fd = 0;
	while (envp[file_fd] && !ft_strnstr(envp[file_fd], "PATH=", 5))
		file_fd++;
	cmd_flags = ft_split(argv[3], ' ');
	ruts = ft_split(&envp[file_fd][5], ':');
	cmd_basic = ft_getcmd(cmd_flags[0], ruts);
	execve(cmd_basic, cmd_flags, envp);
}
