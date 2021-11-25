/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:29:21 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/24 19:50:27 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef	struct s_conn
{
	int		filein;
	int		fileout;
	int		temp;
	char	*limit;
	char	*compar;
}			t_conn;

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int		start_pipex(int argc, char *argv[], char *evnp[]);
char	**format_comands(char *comands);
char	**free_malloc(char **result);

#endif
