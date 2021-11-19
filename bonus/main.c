/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:09:58 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/19 14:27:49 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_conn	saves;

	if (argc < 4)
		return (0);
	if (argv[1] != "HEREDOC")
	{
		saves.filein = open(argv[1], O_RDONLY);
		saves.fileout = open(argv[argc], O_RDWR);
	}
	start_pipex(saves, argc, argv, envp);
	return (0);
}
