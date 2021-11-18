/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:29:12 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/18 15:59:14 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	last_comand(t_tubo tubo, char *file, char *comands)
{
	char	**cmd;
	int		arq;

	cmd = ft_split(comands, ' ');
	cmd[0] = ft_strjoin("/usr/bin", cmd[0]);
	arq = open(file, O_RDWR);
	if (arq == -1)
		return (write(2, "Arq2 Error!", 12));
	else
	{
		close(tubo.tubo[1]);
		dup2(tubo.tubo[0], STDIN_FILENO);
		dup2(1, STDOUT_FILENO);
		close(tubo.tubo[0]);
		execve(cmd[0], cmd, NULL);
	}
	return (0);
}

int	execve_comand(t_tubo tubo, char *comands)
{
	char	**cmd;

	cmd = ft_split(comands, ' ');
	cmd[0] = ft_strjoin("/sr/bin/", cmd[0]);

	close(tubo.tubo[0]);
	dup2(tubo.tubo[1], STDOUT_FILENO);
	close(tubo.tubo[1]);
	execve(cmd[0], cmd, NULL);
	return (0);
}

int	first_comand(t_tubo tubo, char *file, char *comand)
{
	// Não pode splitar dentro do filho, pq não da para dar free.
	char	**cmd;
	int		arq;

	cmd = ft_split(comand, ' ');
	cmd[0] = ft_strjoin("/usr/bin/", cmd[0]);
	arq = open(file, O_RDONLY);
	if (arq == -1)
	{
		return (write(2, "Arq1 Error!", 12));
	}
	else
	{
		dup2(tubo.tubo[1], STDOUT_FILENO);
		dup2(arq, STDIN_FILENO);
		close(tubo.tubo[1]);
		execve(cmd[0], cmd, NULL);
	}
	write(2, "kk", 2);
	return (0);
}

int pipex(int argc, char *argv[], char *envp[])
{
	t_tubo tubo;
	int	pid1;
	int	pid2;
	int	pid3;
	int	i;

	(void)envp;
	(void)pid2;
	(void)i;
	if (pipe(tubo.tubo) == -1)
	{
		return(write(1,"Comunication Error",12));
	}
	pid1 = fork();
	if (pid1 == -1)
		return (write(1,"Fork Error",12));
	if (pid1 == 0)
	{
		first_comand(tubo, argv[1], argv[2]);
	}
	write(2,"Printeiiiiiii\n",10);
	waitpid(pid1, NULL, 0);
	close(tubo.tubo[1]);
	// i = 3;
	// if (argc - 1 != 4)
	// {
	// 	while(i <= argc - 3)
	// 	{
	// 		pid2 = fork();
	// 		if (pid2 == -1)
	// 		{
	// 			return (write(1,"Fork Error",12));
	// 		}
	// 		else
	// 		{
	// 			dup2(tubo.tubo[0], STDIN_FILENO);
	// 			close(tubo.tubo[0]);
	// 			pipe(tubo.tubo);
	// 			execve_comand(tubo, argv[i]);
	// 			i++;
	// 			waitpid(pid2, NULL, 0);
	// 		}
	// 	}
	// }
	pid3 = fork();
	if (pid3 == -1)
	{
		return (write(1,"Fork Error(3)!", 12));
	}
	else
	{
		last_comand(tubo, argv[argc - 1], argv[argc]);
	}
	waitpid(pid3, NULL, 0);
	close(tubo.tubo[0]);
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	pipex(argc, argv, envp);
	return 0;
}
