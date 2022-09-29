/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:54:54 by daparici          #+#    #+#             */
/*   Updated: 2022/09/29 19:50:49 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <xlocale.h>
/* malloc, free, exit */
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "./Libft/libft.h"
//# include "./GetNextLine/get_next_line.h"
# include "./printf/ft_printf.h"
# include <OpenGL/gl.h>
# include <OpenGl/glu.h>
# include <GLUT/glut.h>
/* para write, read, close, access, pipe, dup2, dup, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
/* waitpid, wait */
# include <sys/wait.h>

typedef struct s_pipex
{
	int		**tub;
	int		*pid;
	char	*path;
	char	**ruts;
	int		file;
	int		process;
	int		argc_cp;
	int		x;
}		t_pipex;

void	recursive_process(t_pipex *pipex, char **argv, char **envp);
void	first_child(t_pipex *pipex, char **argv, char **envp);
void	mid_process(t_pipex *pipex, char **argv, char **envp);
void	last_child(t_pipex *pipex, char **argv, char **envp);
void	msg_error(char *msg);
void	close_parent(int *pipe);
char	*find_paths(char **envp);
char	*find_cmd(char *cmd, char **path);

#endif