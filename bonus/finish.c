#include "pipex_bonus.h"

int	finish(char *input, int output, char **cmd)
{
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	execve(cmd[0], cmd, NULL);
}
