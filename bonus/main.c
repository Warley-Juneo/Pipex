#include "pipex_bonus.h"

int main(int argc, char *argv[], char *envp[])
{
	if (argc <= 3)
		return (0);
	start_pipex(argc, argv, envp);
	return 0;
}
