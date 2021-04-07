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
* _puts - Entry point
* @str: Array of char
*
* Description: print the content of str
* Return: Nothing
*/
void _puts(char *str)
{
	int i = 0;

	char flag = 0;

	while (!flag)
	{
		if (str[i] == '\0')
		{
			_putchar('\n');
			flag = 1;
		}
		else
		{
			_putchar(str[i]);
			i++;
		}
	}
}
