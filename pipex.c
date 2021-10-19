#include "pipex.h"

int	pipex(char *argv[], char *envp[])
{
	int	tubo[2];
	int	pid1;
	int	pid2;

	(void)envp;
	if (pipe(tubo) == -1)
		return (write(2, "Comunication Error!", 20));
	pid1 = fork();
	if (pid1 == -1)
		return (write(2, "Fork Error (1)!", 16));
	if (pid1 == 0)
	{
		first_comand(tubo, argv[1], argv[2]);
	}
	close(tubo[1]);
	pid2 = fork();
	if (pid2 == -1)
		return (write(2, "Fork Error (2)!", 16));
	if (pid2 == 0)
	{
		second_comand(tubo, argv[4], argv[3]);
	}
	close(tubo[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
