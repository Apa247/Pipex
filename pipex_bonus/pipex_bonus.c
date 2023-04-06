/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:55:49 by daparici          #+#    #+#             */
/*   Updated: 2023/04/06 19:16:52 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static void	leaks(void)
// {
// 	system("leaks pipex");
// }

t_pipex	*check_here_doc(t_pipex *pipex, char **argv)
{
	int		pipe1[2];
	char	*line;

	pipe(pipe1);
	if (ft_strlen(argv[1]) == 8 && !ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex->limit = ft_substr(argv[2], 0, ft_strlen(argv[2]));
		line = get_next_line(0);
		while (ft_strlen(pipex->limit) != (ft_strlen(line) - 1)
			|| ft_strncmp(line, pipex->limit, ft_strlen(pipex->limit)))
		{
			ft_putstr_fd(line, pipe1[1]);
			free(line);
			line = get_next_line(0);
		}
		free(line);
		close(pipe1[1]);
		pipex->infile = pipe1[0];
		pipex->here_doc = 1;
	}
	else
		pipex->here_doc = 0;
	return (pipex);
}

t_pipex	*params_innit(t_pipex *pipex, int argc, char **envp, char **argv)
{
	if (pipex->here_doc == 1)
	{
		pipex->process = 3;
		pipex->pidchild = ft_calloc((argc - 4), sizeof(int));
		if (!pipex->pidchild)
			msg_error("Error creating pidchild");
	}
	else if (pipex->here_doc == 0)
	{
		pipex->process = 2;
		pipex->pidchild = ft_calloc((argc - 3), sizeof(int));
		if (!pipex->pidchild)
			msg_error("Error creating pidchild");
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_error("Error in first file");
	}
	pipex->index_pidchild = 0;
	pipex->argc_cp = argc;
	pipex->envp_cp = envp_copy(envp);
	pipex->path = find_paths(envp);
	pipex->ruts = ft_split(pipex->path, ':');
	return (pipex);
}

void	close_parent(t_pipex *pipex, int *tub)
{
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
}

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
	pipex = check_here_doc(pipex, argv);
	params_innit(pipex, argc, envp, argv);
	pipe(tub);
	rec_process(tub, pipex, argv);
	close_parent(pipex, tub);
	exit(0);
}

void	rec_process(int *tub_pre, t_pipex *pipex, char **argv)
{
	int		tub_ac[2];

	pipe(tub_ac);
	pipex->pidchild[pipex->index_pidchild] = fork();
	if (pipex->pidchild[pipex->index_pidchild] == 0)
	{
		if ((pipex->process == 2 && pipex->here_doc == 0)
			|| (pipex->process == 3 && pipex->here_doc == 1))
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
			pipex->index_pidchild++;
			rec_process(tub_ac, pipex, argv);
		}
	}
}
