#include "pipex.h"

void ft_exit(t_conn saves, int index)
{
	close(saves.filein);
	close(saves.fileout);
	if (index == 1)
		exit(0);
	exit(127);
}

int execve_comands(t_conn *saves, char **comands, int index)
{
	int fd[2];
	int pid;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
	{
		dup2(saves->filein, STDIN_FILENO);
		close(fd[0]);
		if (index == 1)
			dup2(fd[1], STDOUT_FILENO);
		if (index == 2)
			dup2(saves->fileout, STDOUT_FILENO);
		execve(comands[0], comands, NULL);
	}
	wait(NULL);
	saves->filein = fd[0];
	close(fd[1]);
	return (0);
}

int	start_pipex(int argc, char *argv[], char *envp[])
{
	t_conn 	saves;
	int		index;
	char	**cmd;

	saves.filein = open(argv[1], O_RDONLY);
	saves.fileout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (saves.filein == -1 || saves.fileout == -1)
	{
		close(saves.filein);
		close(saves.fileout);
		exit (1);
	}
	index = 0;
	while (++index <= argc - 3)
	{
		if (format_comands(argv[index + 1], envp) != 0)
		{
			cmd = format_comands(argv[index + 1], envp);
			execve_comands(&saves, cmd, index);
		}
		else
			ft_exit(saves, index);
	}
	return (0);
}
