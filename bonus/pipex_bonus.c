/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:09:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/19 14:27:31 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execve_comands(t_conn saves, char **comands, int index, int argc)
{
	int	fd[2];
	int	process;

	if (pipe(fd) == -1)
		return (0);
	process = fork();
	if (process == -1)
		return (0);
	if (process == 0)
	{
		if (index == 1)
			finish(saves.filein, fd[1], comands);
		else if (index == argc)
			finish(fd[0], saves.fileout, comands);
		else
			finish(saves.temp, fd[1], comands);
	}
	saves.temp = fd[0];
	close(fd[0]);
	close(fd[1]);
	waitpid(process, NULL, 0);
	return (0);
}

int	start_pipex(t_conn saves, int argc, char *argv[], char *envp[])
{
	int		index;
	char	**cmd;

	(void)envp;
	index = -1;
	while (++index <= argc - 1)
	{
		cmd = format_comands(argv[index + 1]);
		execve_comands(saves, cmd, index, argc);
	}
	free_malloc(cmd);
	close(saves.filein);
	close(saves.fileout);
	return (0);
}
