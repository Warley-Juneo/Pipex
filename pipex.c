/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:02:35 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/01/14 21:40:02 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_ptr(char **ptr)
{
	char	**temp;

	temp = ptr;
	while (*ptr)
		free (*ptr++);
	free (temp);
}

void	ft_exit(t_conn saves, int index, char **cmd)
{
	close(saves.filein);
	close(saves.fileout);
	if (cmd)
	{
		free_ptr (cmd);
	}
	if (index == 1)
		exit (0);
	else if (index == 2)
		exit (127);
	else
		exit (0);
}

int	execve_comands(t_conn *saves, char **comands, int index)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
		execve_child(saves, comands, index, fd);
	wait(NULL);
	saves->filein = fd[0];
	close(fd[1]);
	free_ptr(comands);
	return (0);
}

int	start_pipex(int argc, char *argv[], char *envp[])
{
	t_conn	saves;
	int		index;
	char	**cmd;

	saves.filein = open(argv[1], O_RDONLY);
	saves.fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	set_files(saves);
	index = 0;
	while (++index <= argc - 3)
	{
		cmd = format_comands(argv[index + 1], envp);
		if (cmd)
			execve_comands(&saves, cmd, index);
		else
		{
			if (index == 2)
				ft_exit(saves, index, cmd);
		}
	}
	close(saves.filein);
	close(saves.fileout);
	return (0);
}
