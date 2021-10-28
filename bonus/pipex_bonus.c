#include "pipex_bonus.h"

int	first_comand(t_tubo tubo, char *file1, char *comands1)
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
		dup2(tubo.tubo[1], STDOUT_FILENO);
		dup2(arq1, STDIN_FILENO);
		close(tubo.tubo[0]);
		close(tubo.tubo[1]);
		execve(cmd1[0], cmd1, NULL);
	}
	return (0);
}

int	last_comands(t_tubo tubo, char *file2, char *comands2)
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
		dup2(tubo.tubo[0], STDIN_FILENO);
		dup2(arq2, STDOUT_FILENO);
		close(tubo.tubo[0]);
		close(tubo.tubo[1]);
		execve(cmd2[0], cmd2, NULL);
	}
	return (0);
}

int	execve_comand(t_tubo fd, char *comands)
{
	char	**cmd;

	cmd = ft_split(comands, ' ');
	cmd[0] = ft_strjoin("/usr/bin/", cmd[0]);

	dup2(fd.tubo[0], STDIN_FILENO);
	dup2(fd.tubo[1], STDOUT_FILENO);
	fd.temp = fd.tubo[1];
	close(fd.tubo[1]);
	close(fd.tubo[0]);
	execve(cmd[0], cmd, NULL);
	pipe(fd.tubo);
	fd.tubo[0] = fd.temp;
	return (0);
}

int	pipex(char *argv[], char *envp[], int argc)
{
	t_tubo	fd;
	int pid1;
	int pid2;
	int pid3;
	int i;

	(void)envp;

	if (pipe(fd.tubo) == -1)
		perror("Comunication Error");
	pid1 = fork();
	if (pid1 == -1)
		perror("Fork Error!");
	if (pid1 == 0)
		first_comand(fd, argv[1], argv[2]);
	i = 3;
	pid2 = fork();
	if (pid2 == -1)
		perror("Fork Error!");
	if (pid2 == 0)
	{
		while(i < argc - 1)
		{
			execve_comand(fd, argv[i]);
			i++;
		}
	}
	pid3 = fork();
	if (pid3 == -1)
		perror("Fork Error!");
	if (pid3 == 0)
	{
		last_comands(fd, argv[argc - 1], argv[i]);
	}
	close(fd.tubo[0]);
	close(fd.tubo[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	return (0);
}


int main(int argc, char *argv[], char *envp[])
{
	// printf("%d\n", access("/usr/bin/grep", X_OK));
	(void)argc;
	pipex(argv, envp, argc);
	return (0);
}
