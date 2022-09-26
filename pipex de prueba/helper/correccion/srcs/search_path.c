/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:06:54 by jpizarro          #+#    #+#             */
/*   Updated: 2022/03/01 05:33:42 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Tries the different possible paths in the "PATH=" environ variable, and 
**	saves the correct one on path.
*/

#include "../pipex.h"

void	search_path(char *cmd, char *environ[], char **path)
{
	char	**paths;
	char	*pos_path;
	char	*pos_cmd_path;
	int		i;
	int		fd;

	i = -1;
	paths = ft_split(ft_strchr(get_env_path(environ), '/'), ':');
	while (paths[++i])
	{
		pos_path = ft_strjoin(paths[i], "/");
		pos_cmd_path = ft_strjoin(pos_path, cmd);
		free(pos_path);
		fd = open(pos_cmd_path, O_RDONLY);
		if (fd >= 0)
		{
			*path = pos_cmd_path;
			ft_free_split(paths);
			close(fd);
			return ;
		}
		free(pos_cmd_path);
	}
	ft_free_split(paths);
	perror_exit(cmd);
}
