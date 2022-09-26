/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:43:17 by mgonzale          #+#    #+#             */
/*   Updated: 2022/03/31 14:26:37 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1[2];
	int	pid;

	ft_checkerror(argc, argv, envp);
	pipe(fd1);
	pid = fork();
	if (pid == -1)
		exit(write(1, "FALLO EL FORK\n", 14));
	if (pid == 0)
		ft_startproces(fd1, argv, envp);
	else
	{
		close(fd1[FD_W]);
		pid = fork();
		if (pid == -1)
			exit(write(1, "FALLO EL FORK\n", 14));
		if (pid == 0)
			ft_nextproces(fd1, argv, envp);
		else
			ft_closeandwait(fd1);
	}
	return (0);
}
