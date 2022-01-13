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

char	**format_comands(char *comands, char *envp[])
{
	char	**cmd;
	char	**env;
	char	*temp;

	cmd = ft_split(comands, ' ');
	while (ft_strncmp("PATH=", *envp, 4) && *envp++)
		;
	env = ft_split(*envp, ':');
	while(*env)
	{

		*env = ft_strjoin(*env, "/");
		temp = ft_strjoin(*env++, cmd[0]);
		if (access(temp, F_OK) == 0)
		{
			cmd[0] = temp;
			return (cmd);
		}
		free(temp);
	}
	return (0);
}
