/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:45:43 by mgonzale          #+#    #+#             */
/*   Updated: 2022/03/31 14:23:01 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **aux)
{
	int	i;

	i = 0;
	while (aux[i])
	{
		free(aux[i]);
		i++;
	}
}

void	ft_cmdvalid(char **ruts, char *comand)
{
	char	*cmdconcat;
	int		q;

	q = 0;
	while (comand[q] && comand[q] != '/')
		q++;
	if (comand[q] == '/' && !access(comand, X_OK))
		exit(write(1, "COMAND CANT EXECUTE\n", 17));
	if (comand[q] == '\0')
	{
		q = 0;
		cmdconcat = ft_joinmulti(ruts[q], "/", comand);
		while (ruts[q] && cmdconcat && access(cmdconcat, X_OK))
		{
			free(cmdconcat);
			q++;
			cmdconcat = ft_joinmulti(ruts[q], "/", comand);
		}
		if (!ruts[q] || !cmdconcat)
			exit(write(1, "COMAND NOT FOUND\n", 17));
		free(cmdconcat);
	}
}

void	ft_cmderror(char **argvs, char **envt, int q)
{
	char	**paths;
	char	**cmd;

	paths = ft_split(&envt[q][5], ':');
	q = 0;
	while (argvs[2][q] && argvs[2][q] != '/')
		q++;
	if (argvs[2][q] == '/')
		ft_cmdvalid(paths, argvs[2]);
	cmd = ft_split(argvs[2], ' ');
	ft_cmdvalid(paths, cmd[0]);
	ft_free_tab(cmd);
	free(cmd);
	q = 0;
	while (argvs[3][q] != '/' && argvs[3][q] != '\0')
		q++;
	if (argvs[3][q] == '/')
		ft_cmdvalid(paths, argvs[3]);
	cmd = ft_split(argvs[3], ' ');
	ft_cmdvalid(paths, cmd[0]);
	ft_free_tab(cmd);
	free(cmd);
	ft_free_tab(paths);
	free(paths);
}

void	ft_checkerror(int args, char **argvs, char **envt)
{
	int		q;

	if (args != 5)
		exit(write(1, "ARGUMENTOS INCORRECTOS\n", 23));
	q = access(argvs[1], R_OK);
	if (q != 0)
		exit(write(1, "PEMISOS DEL PRIMER ARCHIVO\n", 27));
	if (!envt)
		exit (write(1, "VARIABLES DE ENTORNO OFF\n", 26));
	q = access(argvs[4], F_OK | W_OK);
	if (q != 0)
	{
		if (!access(argvs[4], F_OK))
			exit (write(1, "PERMISOS DEL ULTIMO ARCHIVO\n", 29));
		else
			open(argvs[4], O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	q = 0;
	while (envt[q] && !ft_strnstr(envt[q], "PATH=", 5))
		q++;
	if (!envt[q])
		exit(write(1, "PATH NOT FOUND\n", 15));
	ft_cmderror(argvs, envt, q);
}
