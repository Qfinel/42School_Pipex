/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:52:39 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/02 16:13:00 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	**get_paths(char **envp)
{
	while (!ft_strnstr(*envp, "PATH", 4))
		envp++;
	return (ft_split(*envp + 5, ':'));
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		paths++;
	}
	return (NULL);
}

void	free_strings(t_pip pip)
{
	free(pip.cmd1_args);
	free(pip.cmd2_args);
	if (pip.cmd1 != NULL)
		free(pip.cmd1);
	if (pip.cmd2 != NULL)
		free(pip.cmd2);
}
