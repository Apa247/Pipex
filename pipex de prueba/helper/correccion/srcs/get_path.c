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
**	Tries the raw data as a path, if that doesn't work calls search path.
*/

#include "../pipex.h"

void	get_path(char *cmd, char *environ[], char **path)
{
	int	fd;

	fd = open(cmd, O_RDONLY);
	if (fd >= 0)
	{
		*path = cmd;
		close(fd);
	}
	else
		search_path(cmd, environ, path);
}
