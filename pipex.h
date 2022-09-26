/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:17:36 by daparici          #+#    #+#             */
/*   Updated: 2022/09/26 19:04:20 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		pipe[2];
	char	*path;
	char	**cmd_path;
	char	**cmd_arg;
	char	*cmd;
}		t_pipex;

int		main(int argc, char **argv, char **env);
int		msg_error(char *msg);
void	first_child(t_pipex *pipex, char **argv, char **envp);
void	second_child(t_pipex *pipex, char **argv, char **envp);
char	*find_cmd(char *cmd, char **path);
void	free_child(t_pipex *pipex);
void	close_parent(t_pipex *pipex);
#endif