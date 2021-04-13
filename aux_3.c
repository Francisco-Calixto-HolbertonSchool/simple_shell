#include "holberton.h"
/**
* _which_aux - Entry point
* @path: Array contains diferent path folders
* @cmd: command to execute
* @i: position to search in path
*
* Description: Logic to find a command in paths folders or localy
* Return: Path of looking command or NULL
*/
char *_which_aux(char **path, char *cmd, int i)
{
	char *buff;
	int size = 0;

	if (cmd[0] == '.')
	{
		buff = malloc(sizeof(*cmd));
		if (!buff)
		{
			free(path);
			return (NULL);
		}
		_strcpy(buff, cmd);
	}
	else
	{
		size = (_strlen(path[i]) + 2 + _strlen(cmd));
		buff = malloc(sizeof(char) * size);
		if (!buff)
		{
			free(path);
			return (NULL);
		}
		_strcpy(buff, path[i]);
		_strcat(buff, "/");
		_strcat(buff, cmd);
		return (buff);
	}

	return (cmd);
}
