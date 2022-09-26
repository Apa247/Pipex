/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:34 by rgallego          #+#    #+#             */
/*   Updated: 2022/02/16 17:10:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * function which searchs for the correct full path of the command if possible
 * INPUT:	char **set_of_paths, char **path, char *cmd, int *cnt
 * OUTPUT:	void
 */
static char	*try_path(char **set_of_paths, char *cmd)
{
	char	*path;
	int		cnt;

	cnt = 0;
	path = ft_strjoinsep(set_of_paths[cnt], cmd, "/");
	while (set_of_paths[cnt] && path && access(path, F_OK | X_OK))
	{
		free(path);
		cnt++;
		path = ft_strjoinsep(set_of_paths[cnt], cmd, "/");
	}
	if (!set_of_paths[cnt] || !path)
	{
		free(path);
		return (NULL);
	}
	return (path);
}

/*
 * function which receives a command -cmd- and the environment variables in
 * envp. It searchs for the "PATH=" variable, splits all the paths and later
 * adds them to the cmd in order to test if there is access to the required
 * commmand. 
 * INPUT:	char *cmd, char **envp
 * OUTPUT:	int	:	1	command is valid
 * 					0	invalid command
 */
char	*isvalidcmd(char **cmd, char **envp)
{
	int		cnt;
	char	*path;
	char	**set_of_paths;

	cnt = 0;
	path = NULL;
	while (envp[cnt] && !ft_strnstr(envp[cnt], "PATH=", 5))
		cnt++;
	if (!envp[cnt])
		return (NULL);
	set_of_paths = ft_split(&envp[cnt][5], ':');
	if (!set_of_paths)
		return (NULL);
	path = try_path(set_of_paths, *cmd);
	free_set(set_of_paths);
	if (!path)
		return (NULL);
	free(*cmd);
	*cmd = path;
	return (*cmd);
}

int	father(t_args args, char **envp, int *pipefd)
{
	if (!fork())
		first_child(args, envp, pipefd);
	close(pipefd[PIPE_WR]);
	close(args.fdin);
	if (!fork())
		last_child(args, envp, pipefd);
	close(pipefd[PIPE_RD]);
	close(args.fdout);
	wait(NULL);
	wait(NULL);
	free_set_of_cmd(args);
	return (0);
}

void	first_child(t_args args, char **envp, int *pipefd)
{
	close(pipefd[PIPE_RD]);
	close(args.fdout);
	dup2(args.fdin, STDIN_FILENO);
	dup2(pipefd[PIPE_WR], STDOUT_FILENO);
	close(pipefd[PIPE_WR]);
	execve(args.cmds[0][CMD], args.cmds[0], envp);
}

void	last_child(t_args args, char **envp, int *pipefd)
{
	dup2(pipefd[PIPE_RD], STDIN_FILENO);
	close(pipefd[PIPE_RD]);
	dup2(args.fdout, STDOUT_FILENO);
	execve(args.cmds[1][CMD], args.cmds[1], envp);
}
