/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:07:50 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/02 16:03:33 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_pip pip, int *end, char **envp)
{
	dup2(pip.infd, 0);
	dup2(end[1], 1);
	close(end[0]);
	close(pip.infd);
	execve(pip.cmd1, pip.cmd1_args, envp);
}

void	parent(t_pip pip, int *end, char **envp)
{
	dup2(pip.outfd, 1);
	dup2(end[0], 0);
	close(end[1]);
	close(pip.outfd);
	execve(pip.cmd2, pip.cmd2_args, envp);
}
