/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:09:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/22 23:46:33 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execve_comands(t_conn *saves, char **comands, int index, int argc)
{
	int	fd[2];
	int	process;

	if (pipe(fd) == -1)
		return (0);
	process = fork();
	if (process == -1)
		return (0);
	else if (process == 0)
	{
		dup2(saves->temp, STDIN_FILENO);
		close(fd[0]);
		if (index == argc - 3)
			dup2(saves->fileout, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		execve(comands[0], comands, NULL);
	}
	wait(NULL);
	saves->temp = fd[0];
	close(fd[1]);
	return (0);
}

int	start_pipex(int argc, char *argv[], char *envp[])
{
	t_conn	saves;
	int		index;
	char	**cmd;

	(void)envp;
	saves.temp = open(argv[1], O_RDONLY);
	saves.fileout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	index = 0;
	while (++index < argc - 2)
	{
		cmd = format_comands(argv[index + 1]);
		execve_comands(&saves, cmd, index, argc);
	}
	free_malloc(cmd);
	close(saves.temp);
	close(saves.fileout);
	return (0);
}
