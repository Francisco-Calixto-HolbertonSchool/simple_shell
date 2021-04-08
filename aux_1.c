#include "holberton.h"

/**
 * _which - entry point
 * @cmd: command to find full path
 * Return: full path on success
 *
 */

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

/**
 * special_char_finder - entry point
 * @str: string to search special character
 * @ch: char to search for
 * Return: changed string (or not)
 *
 */

char *special_char_finder(char *str, char ch)
{
	char *aux;
	unsigned int i = 0, l = 0;

	l = _strlen(str);
	while ((str[i] != ch) && str[i])
	{
		i++;
	}
	if (i == l)
		return (str);
	aux = malloc(sizeof(char) * (i + 1));
	str = strncpy(aux, str, i);
	free(aux);
	return (str);
}
