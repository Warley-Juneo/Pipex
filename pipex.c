#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

// pipe = Crea a comunicação
// fork = Duplica o codígo. uma duplicada é o filho
// dup2 = Ainda não sei bem, mais cria uma duplicata do fd para outro fd.
// execve = Seilá oq essa desgraça faz direito.
// waitpid = espera o processo terminar para começar outro.

// func Merge, duplica a join e dar free na A & B;

int	second_comand(int *fd, char *file2, char *comands2)
{
	int		arq2;
	char	**cmd2;

	arq2 = open(file2, O_RDWR);
	cmd2 = malloc(sizeof(char *) * 3);
	cmd2[0] = strdup("/usr/bin/tr"); // ls pode ser qualquer arg;
	cmd2[1] = strdup("b");
	cmd2[2] = strdup("c");
	cmd2[3]	= NULL;

	if (arq2 == -1)
		return (write(2, "Arq2 Error!", 12));
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		dup2(arq2, STDOUT_FILENO);
		close(fd[0]);
		execve(cmd2[0], cmd2, NULL);
		execlp("tr", "tr", "b", "c", NULL);
	}
	return (0);
}

int	first_comand(int *fd, char *file1, char *comands1)
{
	int	arq1;
	char	**cmd1;

	// cmd1 = malloc(sizeof(char *) * 3);
	// cmd1[0] = strdup("/usr/bin/tr");
	// cmd1[1] = strdup("a");
	// cmd1[2] = strdup("b");
	// cmd1[3]	= NULL;
	arq1 = open(file1, O_RDONLY);
	if (arq1 == -1)
		return(write(2, "Arq1 Error!", 11));
	else
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(arq1, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("tr", "tr", "a", "b", NULL);
	}

	return (0);
}

int pipex(char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		return (write(2, "Comunication Error!", 20));
	pid1 = fork();
	if (pid1 == -1)
		return (write(2, "Fork Error (1)!", 16));
	if (pid1 == 0)
	{
		first_comand(fd, argv[1], argv[2]);
	}
	close(fd[1]);
	pid2 = fork();
	if(pid2 == -1)
		return (write(2, "Fork Error (2)!", 16));
	if (pid2 == 0)
	{
		second_comand(fd, argv[4], argv[3]);
	}
	close(fd[0]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	printf("%d\n", access("/usr/bin/lsss", X_OK));
	if (argc != 5)
		return (write(2, "Args Error!", 12));
	pipex(argv);
	return (0);
}
