#include "pipex.h"

int	second_comand(int *tubo, char *file2, char *comands2)
{
	char	**cmd2;
	int 	arq2;

	cmd2 = ft_split(comands2, ' ');
	cmd2[0] = ft_strjoin("/usr/bin/", cmd2[0]);
	arq2 = open(file2, O_RDWR);
	if (arq2 == -1)
		return (write(2, "Arq1 Error!", 12));
	else
	{
		dup2(tubo[0], STDIN_FILENO);
		dup2(arq2, STDOUT_FILENO);
		close(tubo[0]);
		close(tubo[1]);
		execve(cmd2[0], cmd2, NULL);
	}
	return (0);
}
