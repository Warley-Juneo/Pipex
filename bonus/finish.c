#include "pipex_bonus.h"

void	finish(int input, int output, char **cmd)
{
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(input);
	close(output);
	execve(cmd[0], cmd, NULL);
}
