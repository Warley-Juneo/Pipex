/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_comands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:09:51 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/19 14:10:19 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*new_comand(char *cmd)
{
	char	*new_comand;
	int		i;
	int		j;

	new_comand = ft_calloc((ft_strlen(cmd) - 1), sizeof(char *));
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39)
		{
			i++;
			while (cmd[i + 1] != '\0')
			{
				new_comand[j] = cmd[i];
				i++;
				j++;
			}
		}
		i++;
	}
	new_comand[j] = '\0';
	free(cmd);
	return (new_comand);
}

char	**treat_comands(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == 39)
			{
				if (cmd[i][j + 1] == '\0')
					break ;
				cmd[i] = new_comand(cmd[i]);
			}
			j++;
		}
		i++;
	}
	return (cmd);
}

char	**format_comands(char *comands, char *envp[])
{
	char	**cmd;
	char	**env;

	space_treat_comands(comands);
	cmd = ft_split(comands, ' ');
	reverse_space__treat_comands(cmd);
	cmd = treat_comands(cmd);
	while (ft_strncmp("PATH=", *envp, 4) && *envp++)
		;
	env = ft_split(*envp, ':');
	return (join_access(env, cmd));
}
