#include "pipex_bonus.h"

int	second_comands(int *tubo, char *file2, char *comands2)
{
	char	**cmd2;
	int 	arq2;

	cmd2 = ft_split(comands2, ' ');
	cmd2[0] = ft_strjoin("/usr/bin/", cmd2[0]);
	arq2 = open(file2, O_RDWR);
	if (arq2 == -1)
		return (write(2, "Arq2 Error!", 12));
	else
	{
		dup2(tubo[0], STDIN_FILENO);
		dup2(arq2, STDOUT_FILENO);
		close(tubo[0]);
		close(tubo[1]);
		printf("Sua mae\n");
		execve(cmd2[0], cmd2, NULL);
	}
	return (0);
}

int	exec_comands(int *tubo, char *comands)
{
	char	**cmd;

	cmd = ft_split(comands, ' ');
	cmd[0] = ft_strjoin("/usr/bin/", cmd[0]);

	dup2(tubo[0], STDIN_FILENO);
	dup2(tubo[1], STDOUT_FILENO);
	close(tubo[0]);
	close(tubo[1]);
	execve(cmd[0], cmd, NULL);
	return (0);
}

int	first_comands(int *tubo, char *file1, char *comands1)
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

int	pipex_bonus(int argc, char *argv[], char *envp[])
{
	int	tubo[2];
	int	pid1;
	int	pid2;
	int	pid3;
	int	i;

	(void)envp;
	if (pipe(tubo) == -1)
		return (write(2, "Comunication Error!", 20));
	pid1 = fork();
	if (pid1 == -1)
		return (write(2, "Fork Error (1)!", 16));
	if (pid1 == 0)
	{
			first_comands(tubo, argv[1], argv[2]);
	}
	printf("Sei lá\n");
	i = 3;
	while (i < argc - 2)
	{
		pid3 = fork();
		if (pid3 == 0)
			exec_comands(tubo, argv[i]);
		i++;
	}
	printf("Sei láaaaa\n");
	pid2 = fork();
	if (pid2 == -1)
		return (write(2, "Fork Error (2)!", 16));
	if (pid2 == 0)
	{
		printf("%d\n", i);
		second_comands(tubo, argv[i + 1], argv[i]);
	}
	close(tubo[1]);
	close(tubo[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int main(int argc, char *argv[], char *envp[])
{
	// printf("%d\n", access("/usr/bin/ls", X_OK));
	pipex_bonus(argc, argv, envp);
	return (0);
}
