#include "pipex_bonus.h"

char	**format_comands(char *comands)
{
	char **cmd;

	cmd = ft_split(comands, ' ');
	cmd[0] = ft_strjoin("/usr/bin/", cmd[0]);
	return (cmd);
}
