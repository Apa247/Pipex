/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:12:35 by mgonzale          #+#    #+#             */
/*   Updated: 2022/03/31 14:21:50 by mgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define FD_R 0
# define FD_W 1

void	ft_free_tab(char **aux);
void	ft_cmdvalid(char **ruts, char *comand);
void	ft_cmderror(char **argvs, char **envt, int q);
void	ft_checkerror(int args, char **argvs, char **envt);
char	*ft_getcmd(char *cmd, char**ruts);
void	ft_startproces(int *fd, char **argv, char **envp);
void	ft_nextproces(int *fd, char **argv, char **envp);
void	ft_closeandwait(int *fd);

#endif
