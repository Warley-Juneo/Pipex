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
		{
			finish(saves.filein, fd[1], comands);
		}
		else if (index == argc)
		{
			finish(fd[0], saves.fileout, comands);
		}
		else
		{
			finish(saves.temp, fd[1], comands);
		}
	}
	saves.temp = fd[0];
	waitpid(process, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	return (0);
}


int	start_pipex(int argc, char *argv[], char *envp[])
{
	t_conn	saves;
	int		index;
	char	**cmd;

	(void)envp;
	saves.filein = open(argv[1], O_RDONLY);
	saves.fileout = open(argv[argc], O_RDWR);
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
