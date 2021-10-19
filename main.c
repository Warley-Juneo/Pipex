#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	// printf("%d\n", access("/usr/bin/ls", X_OK));
	(void)argc;
	if (argc != 5)
		return (write(2, "Args Error!", 12));
	pipex(argv, envp);
	return (0);
}
