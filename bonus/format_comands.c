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

#include "pipex_bonus.h"

char	**format_comands(char *comands)
{
	char	**cmd;

	cmd = ft_split(comands, ' ');
	cmd[0] = ft_strjoin("/usr/bin/", cmd[0]);
	return (cmd);
}
