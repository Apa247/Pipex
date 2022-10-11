/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:54:54 by daparici          #+#    #+#             */
/*   Updated: 2022/10/11 22:11:25 by daparici         ###   ########.fr       */
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
	char	*path;
	char	**ruts;
	char	**envp_cp;
	int		process;
	int		argc_cp;
	int		infile;
}		t_pipex;

int			check_here_doc(t_pipex *pipex, char **argv, int argc);
t_pipex		params_innit(t_pipex *pipex, int argc);
void		close_parent(t_pipex *pipex, int *tub);
void		rec_process(int *tub_pre, t_pipex *pipex, char **argv);
void		first_child(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac);
void		mid_process(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac);
void		last_child(t_pipex *pipex, char **argv, int *tub_pre, int *tub_ac);
void		msg_error(char *msg);
char		*find_paths(char **envp);
char		*find_cmd(char *cmd, char **path);
char		**envp_copy(char **envp);
size_t		ft_strlen_cp(char **str);

#endif