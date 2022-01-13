#ifndef PIPEX_H
# define PIPEX_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef	struct s_conn
{
	int	filein;
	int	fileout;
}		t_conn;

#ifndef CONST
# define CONST "''"
#endif

int		start_pipex(int argc, char *argv[], char *envp[]);
char	**format_comands(char *comands, char *envp[]);
void 	ft_exit(t_conn saves, int index);

#endif
