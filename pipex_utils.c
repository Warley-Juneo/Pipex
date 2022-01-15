/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:15:03 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/01/14 21:20:19 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_files(t_conn saves)
{
	if (saves.filein == -1 || saves.fileout == -1)
	{
		close(saves.filein);
		close(saves.fileout);
		exit (1);
	}
}

void	execve_child(t_conn *saves, char **comands, int index, int fd[])
{
	dup2(saves->filein, STDIN_FILENO);
	close(fd[0]);
	if (index == 1)
		dup2(fd[1], STDOUT_FILENO);
	if (index == 2)
		dup2(saves->fileout, STDOUT_FILENO);
	if (execve(comands[0], comands, NULL) == -1)
	{
		free_ptr(comands);
		exit(1);
	}
}
