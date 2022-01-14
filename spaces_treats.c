#include "pipex.h"

void 	reverse_space__treat_comands(char **comands)
{
	int	i;
	int	j;

	i = 0;
	while(comands[i])
	{
		j = 0;
		while(comands[i][j])
		{
			if (comands[i][j] == 1)
			{
				comands[i][j] = ' ';
			}
			j++;
		}
		i++;
	}
}

void	space_treat_comands(char *comands)
{
	int	i;

	i = 0;
	while(comands[i])
	{
		if (comands[i] == 39)
		{
			i++;
			if (comands[i] == 39)
				i++;
			while(comands[i] != 39 && comands[i] != '\0')
			{
				if (comands[i] == ' ')
					comands[i] = 1;
				i++;
			}
		}
		i++;
	}
}

char    **join_access(char **env, char **cmd)
{
    char    *temp;
    char    *temp1;
    char    **temp_env;

    temp_env = env;
    while(*env)
	{
		temp = ft_strjoin(*env++, "/");
		temp1 = ft_strjoin(temp, cmd[0]);
		if (access(temp1, F_OK) == 0)
		{
			free_ptr(temp_env);
			free(temp);
			free(cmd[0]);
			cmd[0] = temp1;
			return (cmd);
		}
		free(temp);
		free(temp1);
	}
	write(2, "comand not found: ", 18);
	write(2, cmd[0], ft_strlen(cmd[0]));
	free_ptr(temp_env);
	free_ptr(cmd);
    return (NULL);
}