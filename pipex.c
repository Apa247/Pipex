/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:25:37 by daparici          #+#    #+#             */
/*   Updated: 2022/09/20 21:08:21 by daparici         ###   ########.fr       */
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
	exit(0);
	pipex->cmd_path = ft_split(pipex->path, ':');
	printf("%s\n", pipex->path);
	if (argc != 5)
		return (msg_error("ERROR: Invalid number of arguments"));
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		return (msg_error("FILE ERROR"));
	pipe(pipex->pipe);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		return (msg_error("ERROR: fail when create first child process"));
//	if (pipex->pid1 = 0)
	return (0);		
}