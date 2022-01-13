#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		return (0);
	start_pipex(argc, argv, envp);
	return (0);
}