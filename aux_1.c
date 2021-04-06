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
		strcpy(buff, path[i]);
		strcat(buff, "/");
		strcat(buff, cmd);
		printf("path: %s", buff);
		if (stat(buff, &st) == 0)
		{
			free(path);
			return (buff);
		}
	}
	free(path);
	return (NULL);
}
