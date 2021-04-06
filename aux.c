#include "holberton.h"

int count_dirs(char *path) /* Para para el PATH */
{
	int count = 3, i = 0; /* Count es 3 por PATH , la primer carpeta, y nulo*/
	for(i = 0 ; path[i] != '\0' ; i++)
	{
		if (path[i] == ':')
			count++;
	}
	return (count);
}

int count_sep(char *str, char sep) /* Para contar separadores (universal) */
{
	int count = 0, i = 0;
	for(i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] == sep)
			count++;
	}
	return (count);
}

char **parser(char *str)
{
        size_t j = 0, sep = 0;
        char **res = NULL;
        char *word = NULL;

	sep = count_sep(str, ' ');
	res = malloc(sizeof(char *) * (sep + 2));
	word = strtok(str, " \n");
	while (word)
	{
		res[j] = word;
		word = strtok(NULL, " \n");
		j++;
	}
	res[j] = NULL;
	return (res);
}

char **findpath(void)
{
	int j = 0, size = 0;
	char *path;
	char **res;
	char *word;

	path = _getenv("PATH");
	size = count_dirs(path);
	res = malloc(sizeof(char *) * (size));
	if (!res)
	{
		return (NULL);
	}
	word = strtok(path, ":="); 
        while (word)
        {
                res[j] = word;
		word = strtok(NULL, ":=");
		j++;
	}
	res[j] = NULL;
	return (res);
}

char *_getenv(const char *name)
{
	int i = 0, j = 0;
	extern char **environ;
	char *word;

	for (i = 0; environ[i] != '\0'; i++)
	{
		word = environ[i];
		for (j = 0; name[j] != '\0'; j++)
		{
			if (name[j] != word[j])
				break;
		}
		if ((name[j] == '\0') && (word[j] == '='))
			return (word);
	}
	return NULL;
}
