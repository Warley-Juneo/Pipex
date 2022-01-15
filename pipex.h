/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:02:44 by wjuneo-f          #+#    #+#             */
/*   Updated: 2022/01/14 21:24:50 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_conn
{
	int	filein;
	int	fileout;
}		t_conn;

int		start_pipex(int argc, char *argv[], char *envp[]);
char	**format_comands(char *comands, char *envp[]);
void	ft_exit(t_conn saves, int index, char **cmd);
void	free_ptr(char **ptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nelem, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	reverse_space__treat_comands(char **comands);
void	space_treat_comands(char *comands);
char	**join_access(char **env, char **cmd);
void	set_files(t_conn saves);
void	execve_child(t_conn *saves, char **comands, int index, int fd[]);
#endif
