#include "pipex_bonus.h"

char	**free_malloc(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
		free(result[i++]);
	free(result);
	return (NULL);
}
