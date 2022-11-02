/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:40:57 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/02 16:14:57 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pip
{
	int		infd;
	int		outfd;
	char	*cmd1;
	char	**cmd1_args;
	char	*cmd2;
	char	**cmd2_args;
}	t_pip;

char	*get_cmd(char **paths, char *cmd);
char	**get_paths(char **envp);
void	child(t_pip pip, int *end, char **envp);
void	parent(t_pip pip, int *end, char **envp);
void	pipex(t_pip pip, char **envp);
void	free_strings(t_pip pip);
#endif