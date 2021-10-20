#include "pipex.h"

int	first_comand(int *tubo, char *file1, char *comands1)
{
	char	**cmd1;
	int 	arq1;

	cmd1 = ft_split(comands1, ' ');
	cmd1[0] = ft_strjoin("/usr/bin/", cmd1[0]);
	arq1 = open(file1, O_RDONLY);
	if (arq1 == -1)
		return (write(2, "Arq1 Error!", 12));
	else
	{
		dup2(tubo[1], STDOUT_FILENO);
		dup2(arq1, STDIN_FILENO);
		close(tubo[0]);
		close(tubo[1]);
		execve(cmd1[0], cmd1, NULL);
	}
	return (0);
}
