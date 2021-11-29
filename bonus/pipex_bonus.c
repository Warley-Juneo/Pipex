/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:09:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/24 20:12:06 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execve_docs(t_conn *saves)
{
	int temp;

	temp = open("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	while(1)
	{
		ft_putstr_fd("here_doc> ", 1);
		saves->compar = get_next_line(STDIN_FILENO);
		if(ft_strncmp(saves->compar, saves->limit, ft_strlen(saves->limit)) == 0)
		{
			// free_malloc(&saves->compar);
			close(0);
			break;
		}
		ft_putstr_fd(saves->compar, temp);
		// free_malloc(&saves->compar);
	}
	saves->temp = temp;
	return (0);
}

int	execve_comands(t_conn *saves, char **comands, int index, int argc)
{
	int	fd[2];
	int	process;

	if (pipe(fd) == -1)
		return (0);
	if (saves->here_doc == 1)
		execve_docs(saves);
	process = fork();
	if (process == -1)
		return (0);
	else if (process == 0)
	{
		dup2(saves->temp, STDIN_FILENO);
		if (index == argc - saves->jump3)
			dup2(saves->fileout, STDOUT_FILENO);
		else
			ft_putstr_fd("meio\n", 1);
			dup2(fd[1], STDOUT_FILENO);
		execve(comands[0], comands, NULL);
	}
	wait(NULL);
	saves->here_doc = 0;
	saves->temp = fd[0];
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	start_pipex(int argc, char *argv[], char *envp[])
{
	t_conn	saves;
	int		index;
	char	**cmd;


	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		saves.here_doc = 1;
		saves.jump1 = 3;
		saves.jump2 = 2;
		saves.jump3 = 4;
	}
	else
	{
		saves.jump1 = 2;
		saves.jump2 = 1;
		saves.jump3 = 3;
	}
	(void)envp;
	saves.limit = argv[2];
	saves.limit = ft_strjoin(saves.limit, "\n");
	if (ft_strncmp(argv[1], "here_doc", 9) != 0)
		saves.temp = open(argv[1], O_RDONLY);
	saves.fileout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	index = 0;
	while (++index < argc - saves.jump1)
	{
		cmd = format_comands(argv[index + saves.jump2]);
		execve_comands(&saves, cmd, index, argc);
	}
	// free_malloc(cmd);
	close(saves.temp);
	close(saves.fileout);
	return (0);
}
