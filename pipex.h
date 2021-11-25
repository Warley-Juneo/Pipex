#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef	struct s_tubo
{
	int	tubo[2];
}		t_tubo;


int		pipex(char *argv[], char *envp[]);
int		first_comand(int *tubo, char *file1, char *comands1);
int		second_comand(int *tubo, char *file2, char *comands2);

#endif
