#include "holberton.h"

char *_which(char *cmd)
{
	int i = 0;
	struct stat st;
	static char buff[1024];
	char **path = NULL;

	path = findpath();
	for (i = 1; path[i]; i++)
	{
		_strcpy(buff, path[i]);
		_strcat(buff, "/");
		_strcat(buff, cmd);
		if (stat(buff, &st) == 0)
		{
			free(path);
			return (buff);
		}
	}
	free(path);
	return (cmd);
}
