/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:40:27 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/02 16:13:13 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	pipex(t_pip pip, char **envp)
{
	int		pipe_end[2];
	int		check;
	int		proc;

	check = pipe(pipe_end);
	if (check < 0 || pip.outfd < 0 || read(pip.infd, 0, 0) < 0)
	{
		perror("Error: ");
		exit(1);
	}
	proc = fork();
	if (proc < 0)
	{
		perror("Fork error: ");
		exit(1);
	}
	if (proc == 0)
		child(pip, pipe_end, envp);
	else
		parent(pip, pipe_end, envp);
	close(pipe_end[0]);
	close(pipe_end[1]);
}

int	main(int argc, char	**argv, char **envp)
{
	t_pip	pip;
	char	**paths;

	if (argc != 5)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(1);
	}
	paths = get_paths(envp);
	pip.infd = open(argv[1], O_RDONLY);
	pip.cmd1_args = ft_split(argv[2], ' ');
	pip.cmd2_args = ft_split(argv[3], ' ');
	pip.cmd1 = get_cmd(paths, pip.cmd1_args[0]);
	pip.cmd2 = get_cmd(paths, pip.cmd2_args[0]);
	if (pip.cmd1 == NULL || pip.cmd2 == NULL)
	{
		free_strings(pip);
		write(2, "Command not found\n", 18);
		exit(1);
	}
	pip.outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex(pip, envp);
	free_strings(pip);
	return (0);
}
